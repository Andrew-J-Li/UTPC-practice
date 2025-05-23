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
        ll n, m; cin >> n >> m;
        map<ll,ll> mp;
        vector<ll> a (n), r (n);
        for (ll i = 0; i < n; ++i) cin >> a[i];
        for (ll i = 0; i < n; ++i) cin >> r[i];
        for (ll i = 0; i < n; ++i) {
            for (ll j = a[i] - r[i]; j <= a[i] + r[i]; ++j) {
                ll val = sqrt (r[i] * r[i] - ((a[i] - j) * (a[i] - j)));
                mp[j] = max(mp[j], val);
            }
        }
        ll rslt = 0;
        for (const auto& it : mp) rslt += 2 * it.second + 1;
        cout << rslt << endl;
    }
    return 0;
}