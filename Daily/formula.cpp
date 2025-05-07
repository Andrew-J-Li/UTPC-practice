#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll set_bit(ll n) {
    if (n == 0) return 0;
    ll msb = 0;
    n >>= 1;
    while (n != 0) {
        n >>= 1;
        msb++;
    }
    return (1 << msb);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    for (ll a = 0; a < t; ++a) {
        ll x, y; cin >> x >> y;
        if ((x & y) == 0) cout << 0 << endl;
        else if (x == y) cout << -1 << endl;
        else {
            ll rslt = 0;
            while (((x + rslt) & (y + rslt)) != 0) {
                ll temp = (x + rslt) & (y + rslt);
                ll temp_2 = (x + rslt) ^ (y + rslt);
                ll msb_2 = set_bit(temp_2);
                temp &= -temp; temp_2 &= -temp_2;
                temp--; temp_2--;
                rslt += (temp_2 < temp) ? (msb_2 < temp) ? msb_2 : temp - temp_2 : temp_2 - temp;
            }
            cout << rslt << endl;
        }
    }
}