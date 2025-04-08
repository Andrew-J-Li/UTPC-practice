#include <bits/stdc++.h>

#define MOD (long long) 1e9 + 7
#define ll long long
using namespace std;

ll bin_exp (ll a, ll b);
int main() {
    ll n; cin >> n;
    ll tn; tn = n;
    map<ll, ll> f;
    for (ll i = 2; i * i <= n; ++i) {
        while (tn % i == 0) {
            tn /= i;
            f[i]++;
        }
    }
    ll phi = 1;
    for (auto const& it : f) {
        phi *= bin_exp(it.first, it.second - 1);
        phi = phi * (it.first - 1) % MOD;
        phi = phi % MOD;
    }

    cout << phi << endl;
}

ll bin_exp (ll a, ll b) {
    ll rslt = 1;
    while (b > 0) {
        if (b & 1) rslt = rslt * a % MOD;
        rslt = rslt % MOD;
        a = a * a % MOD;
        a = a % MOD;
        b >>= 1;
    }
    return rslt % MOD;
}