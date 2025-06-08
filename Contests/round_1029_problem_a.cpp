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
        ll n, x; cin >> n >> x;
        vector<ll> doors (n);
        for (ll i = 0; i < n; ++i) {
            cin >> doors[i];
        }
        bool x_on = false;
        bool rslt = true;
        for (ll i = 0; i < n; ++i) {
            if (doors[i] == 0 && x_on) x--;
            else if (doors[i] == 1) {
                if (x_on && x <= 0) rslt = false;
                else if (x_on) x--;
                else { x_on = true; x--; }
            }
        }
        if (rslt) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}