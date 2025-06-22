#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

ll bin_exp (ll a, ll b) {
    a %= MOD; b %= MOD;
    ll rslt = 1;
    while (b != 0) {
        if (b & 1) rslt = (rslt * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return rslt % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll a, b, c;
        cin >> a >> b >> c;
        ll m = (((a - 1) * c) + 1) % MOD;
        ll n = bin_exp(2LL, m);
        cout << m << " " << n - 1 << endl;
    }
    return 0;
}