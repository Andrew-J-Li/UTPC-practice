#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, a, b, c; cin >> n >> a >> b >> c;
    vector<int> lengths = {a, b, c};
    vector<int> dp (n + 1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        if (dp[i] == -1) continue;
        for (int j : lengths) {
            if (i + j > n) continue;
            dp[i + j] = max(dp[i + j], dp[i] + 1);
        }
    }
    cout << dp[n] << endl;
}