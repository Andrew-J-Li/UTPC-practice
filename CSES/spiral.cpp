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
        ll y, x; cin >> y >> x;
        ll rslt = 0;
        ll box = max(x, y);
        if (box % 2 == 1) {
            rslt = box * box;
            rslt -= (y - 1);
            rslt -= (box - x);
        } else {
            rslt = ((box - 1) * (box - 1)) + 1;
            rslt += (y - 1);
            rslt += (box - x);
        }
        cout << rslt << endl;
    }
}