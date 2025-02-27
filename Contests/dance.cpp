#include <iostream>
#include <vector>


using namespace std;

int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;

    vector<bool> c (n, false);
    vector<vector<int>> dp(4, vector<int>(n + 1, 0));

    if (t[0] == 'N') dp[0][0] = 1;
    else if (t[0] == 'E') dp[1][0] = 1;
    else if (t[0] == 'S') dp[2][0] = 1;
    else dp[3][0] = 1;

    int m = 0;
    for (int i = 1; i < n; i++) {
        if (t[i] == 'E') {
            dp[0][i] = max(dp[1][i - 1], dp[3][i - 1]);
            dp[2][i] = max(dp[1][i - 1], dp[3][i - 1]);
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]) + 1;
            dp[3][i] = max(dp[0][i - 1], dp[2][i - 1]);
        } else if (t[i] == 'S') {
            dp[0][i] = max(dp[1][i - 1], dp[3][i - 1]);
            dp[2][i] = max(dp[1][i - 1], dp[3][i - 1]) + 1;
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]);
            dp[3][i] = max(dp[0][i - 1], dp[2][i - 1]);
        } else if (t[i] == 'W') {
            dp[0][i] = max(dp[1][i - 1], dp[3][i - 1]);
            dp[2][i] = max(dp[1][i - 1], dp[3][i - 1]);
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]);
            dp[3][i] = max(dp[0][i - 1], dp[2][i - 1]) + 1;
        } else {
            dp[0][i] = max(dp[1][i - 1], dp[3][i - 1]) + 1;
            dp[2][i] = max(dp[1][i - 1], dp[3][i - 1]);
            dp[1][i] = max(dp[0][i - 1], dp[2][i - 1]);
            dp[3][i] = max(dp[0][i - 1], dp[2][i - 1]);
        }
    }

    m = max(m, dp[0][n - 1]);
    m = max(m, dp[1][n - 1]);
    m = max(m, dp[2][n - 1]);
    m = max(m, dp[3][n - 1]);

    cout << m << endl;
}