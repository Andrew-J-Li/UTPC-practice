#include <bits/stdc++.h>


using namespace std;


int main() {
    int q, k;
    cin >> q >> k;
    
    vector<int> b;

    for (int i = 0; i < q; i++) {
        vector<int> dp(k + 1, -1);
        dp[0] = 0;
        string temp;
        cin >> temp;
        int num;
        cin >> num;
        if (temp == "+") {
            b.push_back(num);
        }
        if (temp == "-") {
            auto it = std::find(b.begin(), b.end(), num);
            if (it != b.end()) {
                b.erase(it);
            }
        }

        for (int j = 0; j < (int) size(b); j++) {
            vector<bool> c(k + 1, false);
            for (int l = b[j]; l <= k; l++) {
                if (dp[l] == -1) {
                    continue;
                }
                if (c[l]) {
                    continue;
                }
                if (dp[l - b[j]] + 1 > dp[l]) {
                    c[l] = true;
                }
                dp[l] = min(dp[l - b[j]] + 1, dp[l]);
            }
        }
        
        cout << dp[k] << '\n';
    }
}