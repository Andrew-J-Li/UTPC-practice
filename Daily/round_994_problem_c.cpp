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
        ll n, x, y; cin >> n >> x >> y;
        x--; y--;
        vector<ll> rslt (n);
        ll prev = ((y & 1) ? 0 : 1);
        for (ll i = 0; i < n; ++i) {
            rslt[i] = prev;
            prev = ((prev == 0) ? 1 : 0);
        }
        if (rslt[y] == 1 && rslt[x] == 1) rslt[y] = 2;
        if ((n & 1)) {
            ll pr = rslt[n - 2], nx = rslt[0], curr = 0;
            while (curr == pr || curr == nx) curr++;
            rslt[n - 1] = curr;
        }
        for (ll it : rslt) cout << it << " ";
        cout << endl;
    }
    return 0;
}