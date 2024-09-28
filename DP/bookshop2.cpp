#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> price(n, 0);
    vector<int> page(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> page[i];
    }

    vector<int> dp(x + 1, 0);
    int rslt = 0;

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= price[i]; j--) {
            dp[j] = max(dp[j], dp[j - price[i]] + page[i]);
            rslt = max(rslt, dp[j]);
        }
    }

    cout << rslt << '\n';
}
