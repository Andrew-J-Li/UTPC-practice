#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int find_msb (int n) {
    if (n == 0) return 0;
    int msb = 0;
    n /= 2;
    while (n != 0) {
        n /= 2;
        msb++;
    }
    return msb;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<bool> s (n + 1);
        vector<int> g;
        if (n & 1) {
            cout << n << endl;
            g.push_back(1);
            g.push_back(3);
            g.push_back(n - 1);
            g.push_back(n);
            s[1] = true;
            s[3] = true;
            s[n - 1] = true;
            s[n] = true;
        } else {
            int ans = find_msb(n);
            cout << ((1 << (ans + 1)) - 1) << endl;
            if ((1 << ans) != n) {
                g.push_back(n);
                g.push_back(n - 1);
                g.push_back((1 << ans) - 1);
                s[n] = true;
                s[n - 1] = true;
                s[(1 << ans) - 1] = true;
            } else {
                g.push_back(1);
                g.push_back(3);
                g.push_back(n - 2);
                g.push_back(n - 1);
                g.push_back(n);
                s[1] = true;
                s[3] = true;
                s[n - 2] = true;
                s[n - 1] = true;
                s[n] = true;
            }
        }
        for (int i = 1; i <= n; ++i) if (!s[i]) cout << i << " ";
        for (int i = 0; i < g.size(); ++i) cout << g[i] << " ";
        cout << endl;
    }
    return 0;
}