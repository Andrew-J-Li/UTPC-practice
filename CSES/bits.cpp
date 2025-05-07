#include <bits/stdc++.h>
#define endl "\n"
#define MOD 1000000007
#define ll long long
using namespace std;

ll bin_exp(ll a, ll b) {
    ll rslt = 1;
    while (b) {
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

    ll n; cin >> n;
    ll rslt = bin_exp(2, n);
    cout << rslt << endl;
}