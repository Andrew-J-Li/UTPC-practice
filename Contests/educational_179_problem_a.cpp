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
        ll x; cin >> x;
        ll a = 0, b = 0, c = 0;
        ll rslt = 0;
        while (a < x || b < x || c < x) {
            ll curr = min(a, min(b, c));
            if (a == curr) a = (2 * min(b, c)) + 1;
            else if (b == curr) b = (2 * min(a, c)) + 1;
            else c = (2 * min(a, b)) + 1;
            rslt++;
        }
        cout << rslt << endl;
    }
    return 0;
}