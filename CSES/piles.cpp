#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    for (ll a = 0; a < t; ++a) {
        ll x, y; cin >> x >> y;
        if ((x + y) % 3 != 0) cout << "NO" << endl;
        else if (y * 2 < x || x * 2 < y) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}