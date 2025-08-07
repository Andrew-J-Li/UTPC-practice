#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

ll gcd (ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll arr[n];
    for (ll i = 0; i < n; ++i) cin >> arr[i];
    ll pf[n], sf[n];

    pf[0] = arr[0];
    for (ll i = 1; i < n; ++i) pf[i] = gcd (pf[i - 1], arr[i]);
    sf[n - 1] = arr[n - 1];
    for (ll i = n - 2; i >= 0; --i) sf[i] = gcd (sf[i + 1], arr[i]);

    ll rslt = 1;
    for (ll i = 0; i < n; ++i) {
        if (i == 0) rslt = max (rslt, sf[i + 1]);
        else if (i == n - 1) rslt = max (rslt, pf[i - 1]);
        else rslt = max (rslt, gcd (sf[i + 1], pf[i - 1]));
    }

    cout << rslt << endl;
    return 0;
}