#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        ll n, m, a, b; cin >> n >> m >> a >> b;
        ll rslt = LLONG_MAX;
        for (int i = 0; i < 4; ++i) {
            ll nt = n, mt = m, tr = 1;
            if (i == 0) nt -= (a - 1);
            else if (i == 1) mt -= (b - 1);
            else if (i == 2) nt -= (nt - a);
            else mt -= (mt - b);
            while (!(nt == 1 && mt == 1)) {
                if (nt > mt) {
                    if (nt % 2 == 1) nt++;
                    nt /= 2;
                } else {
                    if (mt % 2 == 1) mt++;
                    mt /= 2;
                }
                tr++;
            }
            rslt = min(rslt, tr);
        }
        cout << rslt << endl;
    }
}