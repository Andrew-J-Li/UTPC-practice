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
        ll b, c, d; cin >> b >> c >> d;
        ll a = 0;
        bool good = true;

        for (ll bit = 0; bit < 62; ++bit) {
            ll bb = (b >> bit) & 1;
            ll cb = (c >> bit) & 1;
            ll db = (d >> bit) & 1;
            bool hit = false;
            for (ll ab = 0; ab <= 1; ++ab) {
                if ((ab | bb) - (ab & cb) == db){
                    if (ab == 1) a |= (1LL << bit);
                    hit = true;
                    break;
                }
            }
            if (!hit) { good = false; break; }
        }
        if (good && ((a | b) - (a & c)) != d) good = false;
        if (good) cout << a << endl;
        else cout << -1 << endl;
    }
    return 0;
}