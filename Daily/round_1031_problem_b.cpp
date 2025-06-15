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
        ll w, h, a, b; cin >> w >> h >> a >> b;
        ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        bool good = false;
        if (x1 == x2) {
            if (abs(y1 - y2) % b == 0) good = true;
        }
        else if (y1 == y2) {
            if (abs(x1 - x2) % a == 0) good = true;
        }
        else if (abs(y1 - y2) % b == 0 || abs (x1 - x2) % a == 0) good = true;
        if (good) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}