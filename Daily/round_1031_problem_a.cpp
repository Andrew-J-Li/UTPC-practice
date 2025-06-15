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
        ll k, a, b, x, y; cin >> k >> a >> b >> x >> y;
        ll rslt = 0;
        if (x < y) {
            ll curr = ceil((double) (k - a) / (double) x);
            if ((k - a) % x == 0) curr++;
            if (k >= a) {
                rslt += curr;
                k -= curr * x;
            }
            curr = ceil((double)(k - b) / (double) y);
            if ((k - b) % y == 0) curr++;
            if (k >= b) {
                rslt += curr;
                k -= curr * y;
            }
        } else {
            ll curr = ceil((double)(k - b) / (double) y);
            if ((k - b) % y == 0) curr++;
            if (k >= b) {
                rslt += curr;
                k -= curr * y;
            }
            curr = ceil((double) (k - a) / (double) x);
            if ((k - a) % x == 0) curr++;
            if (k >= a) {
                rslt += curr;
                k -= curr * x;
            }
        }
        cout << rslt << endl;
    } 
    return 0;
}