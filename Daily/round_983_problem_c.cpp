#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        vector<ll> v (n);
        for (ll i = 0; i < n; ++i) cin >> v[i];
        sort(v.begin(), v.end());
        ll rslt = LLONG_MAX;
        for (ll i = 0; i < n - 1; ++i) {
            ll t = v[i] + v[i + 1];
            ll lo = 0, hi = n - 1, g = 0;
            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                if (t <= v[mid]) hi = mid - 1;
                else {
                    g = mid;
                    lo = mid + 1;
                }
            }
            rslt = min(rslt, i + (n - 1 - g));
        }
        cout << rslt << endl;
    }
    return 0;
}