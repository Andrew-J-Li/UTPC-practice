#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int fact[200001];

ll bin_exp (ll a, ll b) {
    if (a == 0) return 0;
    ll rslt = 1;
    while (b != 0) {
        if (b & 1) rslt = (rslt * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return rslt;
}

ll inv (ll a) {
    return bin_exp (a, MOD - 2);
}

ll nCk (ll n, ll k) {
    return ((fact[n] * inv(fact[k]) % MOD) * inv(fact[n - k])) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    fact[0] = 1;
    for (ll i = 1; i <= 200000; ++i) fact[i] = (fact[i - 1] * i) % MOD;

    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        ll ct = 0;
        for (ll i = 0; i < n; ++i) {
            ll temp; cin >> temp;
            if (temp) ct++;
        }
        ll rslt = 0;
        for (ll i = (k / 2) + 1; i <= min(ct, k); ++i) {
            ll curr = nCk (ct, i);
            if (n - ct < k - i) continue;
            curr = (curr * nCk(n - ct, k - i)) % MOD;
            rslt = (rslt + curr) % MOD;
        }
        cout << rslt << endl;
    }
    return 0;
}