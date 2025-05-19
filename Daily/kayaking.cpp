#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    n *= 2;
    vector<int> kayaks (n);
    int rslt = INT_MAX;
    for (int i = 0; i < n; ++i) cin >> kayaks[i];
    sort(kayaks.begin(), kayaks.end());
    for (int i = 0; i < n; ++i) {
        vector<bool> used (n);
        used[i] = true;
        for (int j = 0; j < n; ++j) {
            if (used[j]) continue;
            used[j] = true;
            vector<bool> taken (n);
            int tr = 0;
            for (int k = 0; k < n; ++k) {
                if (used[k] || taken[k]) continue;
                int nx = k + 1;
                while (used[nx] || taken[nx]) nx++;
                tr += kayaks[nx] - kayaks[k];
                taken[nx] = true;
                taken[k] = true;
            }
            rslt = min(rslt, tr);
            used[j] = false;
        }
    }
    cout << rslt << endl;
}