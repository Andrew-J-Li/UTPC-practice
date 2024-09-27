#include <bits/stdc++.h>
#define ll long long
#define vt vector
#define endl '\n'
#define sz(x) (int)x.size()
#define pb push_back
#define pf push_front
#define uset unordered_set
#define umap unordered_map
struct pii {
    int x, y;
};


using namespace std;

int main() {
    int n;
    cin >> n;
    vt<string> grid(n, "");
    vt<vt<int>> dp(n, vt<int>(n, 0));
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    bool done = false;
    for (int i = 0; i < n; i++) {
        if (grid[0][0] == '*' || grid[n - 1][n - 1] == '*') {
            cout << 0 << '\n';
            done = true;
            break;
        }
        for (int j = 0; j < n; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (grid[i][j] == '*') {
                continue;
            }
            if (i - 1 < 0) {
                dp[i][j] = dp[i][j - 1];
                continue;
            }
            if (j - 1 < 0) {
                dp[i][j] = dp[i - 1][j];
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
        }
    }
    if (!done) {
        cout << dp[n - 1][n - 1] << '\n';
    }
}