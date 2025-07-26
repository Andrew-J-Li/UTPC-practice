#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<pair<int, int>> days;
        for (int i = 0; i < n; ++i) {
            int a; cin >> a;
            if (days.empty()) {
                days.push_back({a, 1});
                continue;
            }
            if (a == days[days.size() - 1].first) days[days.size() - 1].second++;
            else days.push_back({a, 1});
        }

        ll rslt = 0;
        for (int i = 0; i < days.size(); ++i) {
            if (days[i].first == 1) continue;
            ll span = days[i].second + 1;
            rslt += span / (k + 1);
        }
        cout << rslt << endl;
    }
    return 0;
}