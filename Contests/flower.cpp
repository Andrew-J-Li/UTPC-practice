#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dp (m + 1, vector<long long> (n));
    vector<vector<long long>> g (n, vector<long long> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp = 0;
            cin >> temp;
            g[i][j] = temp;
        }
    }

    long long rslt = LONG_LONG_MIN;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            dp[i][j] = max(dp[i - 1][(j == 0) ? n - 1 : j - 1], dp[i - 1][(j == n - 1) ? 0 : j + 1]) + g[j][i - 1];
            if (i == m) rslt = max(rslt, dp[i][j]);
        }
    }

    cout << rslt << endl;
}