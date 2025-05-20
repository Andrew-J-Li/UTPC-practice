#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, k , t; cin >> n >> m >> k >> t;
    vector<pair<int, int>> waste;
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        waste.push_back({a, b});
    }
    sort(waste.begin(), waste.end());
    for (int i = 0; i < t; ++i) {
        int a, b; cin >> a >> b;
        int lo = 0, hi = waste.size() - 1, lb = -1, hb = waste.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (waste[mid].first >= a) hi = mid - 1;
            else {
                lb = mid;
                lo = mid + 1;
            }
        }
        lo = 0, hi = waste.size() - 1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (waste[mid].first <= a) lo = mid + 1;
            else {
                hb = mid;
                hi = mid - 1;
            }
        }
        lb++; hb--;
        lo = lb, hi = hb; int rslt = -1; bool w = false;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (waste[mid].second == b) {
                w = true;
                break;
            } else if (waste[mid].second < b) {
                rslt = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        if (w) cout << "Waste" << endl;
        else {
            int count = ((a - 1) * m) + b;
            count -= ((rslt == -1) ? lb : (rslt + 1));
            if ((count % 3) == 1) cout << "Carrots" << endl;
            else if ((count % 3) == 2) cout << "Kiwis" << endl;
            else cout << "Grapes" << endl;
        }
    }
}