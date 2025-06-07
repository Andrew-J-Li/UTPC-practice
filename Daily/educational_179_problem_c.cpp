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
        vector<ll> ps (n + 2);
        for (ll i = 0; i < m; ++i) {
            ll temp; cin >> temp;
            ps[1]++;
            ps[temp + 1]--;
        }
        ll sum = 0;
        for (ll i = 0; i < n + 2; ++i) {
            sum += ps[i];
            ps[i] = sum;
        }
        ll lo = 1, hi = n - 1;
        ll rslt = 0;
        while (lo <= hi) {
            ll cl = ps[lo];
            ll ch = ps[hi];
            if (cl != 0 && ch != 0) {
                if (lo == hi) rslt += min(cl, ch) * (max(cl, ch) - 1);
                else rslt += 2 * min(cl, ch) * (max(cl, ch) - 1);
            }
            lo++;
            hi--;
        }
        cout << rslt << endl;
    }
    return 0;
}