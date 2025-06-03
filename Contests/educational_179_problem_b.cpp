#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<ll> fib = {0, 1};
    for (ll i = 2; i <= 12; ++i) fib.push_back(fib[i - 1] + fib[i - 2]);
    fib.erase(fib.begin());

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        for (ll i = 0; i < m; ++i) {
            ll w, l, h; cin >> w >> l >> h;
            ll tw = fib[n], tl = fib[n], th = fib[n + 1];
            vector<ll> a = {w, l, h};
            vector<ll> b = {tw, tl, th};
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            if (b[0] > a[0] || b[1] > a[1] || b[2] > a[2]) cout << 0;
            else cout << 1;
        }
        cout << endl;
    }
    return 0;
}