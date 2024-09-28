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

    vector<int> dp(x + 1, -1);
    dp[0] = 0;
    int rslt = 0;
    for (int i = 0; i < n; i++) {
        unordered_set<int> h;
        for (int j = 0; j < x; j++) {
            if (j + price[i] > x) {
                continue;
            }

            if (dp[j] == -1) {
                continue;
            }
            
            if (h.count(j)) {
                continue;
            }

            if (dp[j] + page[i] > dp[j + price[i]]) {
                h.insert(j + price[i]);
            }
            dp[j + price[i]] = max(dp[j + price[i]], dp[j] + page[i]);
            rslt = max(rslt, dp[j + price[i]]);
        }
    }
    
    cout << rslt << '\n';
}