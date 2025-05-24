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
        int n, m, k; cin >> n >> m >> k;
        vector<int> dp (n + 2, -1);
        string s; cin >> s;
        for (int i = 0; i <= min(n + 1, m); ++i) dp[i] = max(dp[i], k);
        for (int i = 1; i <= n; ++i) {
            if (s[i - 1] == 'C' || dp[i] == -1) continue;
            if (s[i - 1] == 'L') {
                for (int j = 1; j <= min(m, n - i + 1); ++j) dp[i + j] = max(dp[i + j], dp[i]);
            } else if (s[i - 1] == 'W'){
                if (dp[i] == 0) continue;
                dp[i + 1] = max(dp[i] - 1, dp[i + 1]);
            }
        }
        if (dp[n + 1] >= 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}