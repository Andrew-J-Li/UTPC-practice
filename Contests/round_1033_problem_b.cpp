#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, s; cin >> n >> s;
        ll rslt = 0;
        for (ll i = 0; i < n; ++i) {
            ll dx, dy, x, y;
            cin >> dx >> dy >> x >> y;
            if (x == (s / 2) && y == (s / 2)) { rslt++; continue; }
            if (x == y && dx == dy) { rslt++; continue; }
            if (x + y == s && dx != dy) { rslt++; continue; }
        }
        cout << rslt << endl;
    }
    return 0;
}