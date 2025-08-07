#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T; cin >> T;
    while (T--) {
        ll n, x; cin >> n >> x;
        string s; cin >> s;

        vector<ll> pf (n);
        vector<ll> sf (n);
        for (ll i = 0; i < n; ++i) {
            pf[i] = (i == 0) ? 0 : pf[i - 1];
            pf[i] = (s[i] == '#') ? i + 1 : pf[i];
        }
        for (ll i = n - 1; i >= 0; --i) {
            sf[i] = (i == n - 1) ? n : sf[i + 1];
            sf[i] = (s[i] == '#') ? i : sf[i];
        }
        x--;
        ll l_res = (x == 0) ? 0 : pf[x - 1];
        ll r_res = n - ((x == n - 1) ? n : sf[x + 1]);
        if (l_res <= r_res) l_res = x;
        else r_res = n - (x + 1);
        cout << 1 + min(l_res, r_res) << endl;
    }
    return 0;
}