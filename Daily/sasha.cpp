#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<ll> bar (n);
        for (ll i = 0; i < n; ++i) cin >> bar[i];
        sort(bar.begin(), bar.end());
        ll rslt = 0;
        unordered_set<ll> visited;
        if (n % 2 == 0) {
            ll b_med = (n / 2) - 1, t_med = (n / 2);
            rslt += bar[t_med] - bar[b_med] + 1;
            visited.insert(bar[b_med]);
            visited.insert(bar[t_med]);
            for (ll i = b_med - 1; i >= 0; --i) {
                if (visited.count(bar[i])) continue;
                if (k >= 2 * (b_med - i)) {
                    rslt += bar[i + 1] - bar[i] + 1 - (visited.count(bar[i + 1]) ? 1 : 0);
                    visited.insert(bar[i]);
                }
            }
            for (ll i = t_med + 1; i < n; ++i) {
                if (visited.count(bar[i])) continue;
                if (k >= 2 * (i - t_med)) {
                    rslt += bar[i] - bar[i - 1] + 1 - (visited.count(bar[i - 1]) ? 1 : 0);
                    visited.insert(bar[i]);
                }
            }
        } else {
            ll med = n / 2;
            rslt++;
            visited.insert(bar[med]);
            for (ll i = med - 1; i >= 0; --i) {
                if (visited.count(bar[i])) continue;
                if (k >= (2 * (med - i)) - 1) {
                    rslt += bar[i + 1] - bar[i] + 1 - (visited.count(bar[i + 1]) ? 1 : 0);
                    visited.insert(bar[i]);
                }
            }
            for (ll i = med + 1; i < n; ++i) {
                if (visited.count(bar[i])) continue;
                if (k >= (2 * (i - med)) - 1) {
                    rslt += bar[i] - bar[i - 1] + 1 - (visited.count(bar[i - 1]) ? 1 : 0);
                    visited.insert(bar[i]);
                }
            }
        }
        cout << rslt << endl;
    }
}