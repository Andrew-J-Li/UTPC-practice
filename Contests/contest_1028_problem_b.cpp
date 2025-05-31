#include <bits/stdc++.h>
#define endl "\n"
#define MOD 998244353LL
#define ll long long
using namespace std;

ll bin_exp (ll a, ll b) {
    ll rslt = 1;
    while (b != 0) {
        if (b & 1) rslt = (rslt * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return rslt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while(t--) {
        ll n; cin >> n;
        vector<ll> p (n), q(n);
        for (ll i = 0; i < n; ++i) cin >> p[i];
        for (ll i = 0; i < n; ++i) cin >> q[i];
        vector<pair<ll, ll>> ps (n);
        vector<pair<ll, ll>> qs (n);
        for (ll i = 0; i < n; ++i) {
            ps[i] = ((i == 0) ? make_pair(0LL, 0LL) : ps[i - 1]);
            qs[i] = ((i == 0) ? make_pair(0LL, 0LL) : qs[i - 1]);
            if (q[i] > qs[i].first) { qs[i].first = q[i]; qs[i].second = i; }
            if (p[i] > ps[i].first) { ps[i].first = p[i]; ps[i].second = i; }
        }
        vector<ll> r (n);
        for (ll i = 0; i < n; ++i) {
            ll idx = 0;
            if (qs[i].first == ps[i].first) {
                ll curr = bin_exp(2, qs[i].first);
                if (p[i - qs[i].second] >= q[i - ps[i].second]) idx = p[i - qs[i].second];
                else idx = q[i - ps[i].second];
                curr = (curr + bin_exp(2, idx)) % MOD;
                r[i] = curr;
            } else {
                ll curr = bin_exp(2, ((qs[i].first > ps[i].first) ? qs[i].first : ps[i].first));
                if (qs[i].first > ps[i].first) idx = p[i - qs[i].second];
                else idx = q[i - ps[i].second];
                curr = (curr + bin_exp(2, idx)) % MOD;
                r[i] = curr;
            }
        }
        for (ll i : r) cout << i << " ";
        cout << endl;
    }
    return 0;
}