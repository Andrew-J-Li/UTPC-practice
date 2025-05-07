#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m, q; cin >> n >> m >> q;
    string s1, s2; cin >> s1 >> s2;
    if (m > n) {
        for (int a = 0; a < q; ++a) {
            int x, y;
            cin >> x >> y;
        }
        for (int a = 0; a < q; ++a) cout << 0 << endl;
    } else {
        vector<int> pf (n);
        vector<int> sf (n);
        for (int i = 0; i < n; ++i) {
            pf[i] += (i == 0) ? 0 : pf[i - 1];
            sf[i] += (i == 0) ? 0 : sf[i - 1];
            if (i < n - m + 1) {
                string temp = s1.substr(i, m);
                if (s1.substr(i, m) == s2) {
                    pf[i]++;
                    sf[i + m - 1]++;
                }
            }
        }
        for (int a = 0; a < q; ++a) {
            int lo, hi; cin >> lo >> hi;
            lo--; hi--;
            int rslt = sf[hi] - ((lo == 0) ? 0 : pf[lo - 1]);
            cout << max(0, rslt) << endl;
        }
    }
}