#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll a, b, x, y; cin >> a >> b >> x >> y;
        if (b == a - 1 && (a & 1)) { cout << y << endl; continue; }
        if (b < a) { cout << -1 << endl; continue; }
        if (b == a) { cout << 0 << endl; continue; }
        if (y < x) {
            ll res = b - a;
            if ((res & 1)) {
                ll cty = (a & 1) ? res / 2 : (res / 2) + 1;
                cout << cty * y + (res - cty) * x << endl;
            } else {
                ll cty = res / 2;
                cout << cty * y + (res - cty) * x << endl;
            }
        } else {
            cout << (b - a) * x << endl;
        }
    }
    return 0;
}