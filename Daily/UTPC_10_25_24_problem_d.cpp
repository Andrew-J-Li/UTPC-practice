#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll gcd (ll a, ll b) {
    while (b != 0) {
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
    map<pair<ll, ll>, ll> pts;
    for (ll i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        ll div = gcd(a, b);
        a /= div; b /= div;
        pts[{a, b}]++;
    }
    ll rslt = 0;
    for (const auto& it : pts) rslt = max(rslt, it.second);
    cout << rslt << endl;

    return 0;
}