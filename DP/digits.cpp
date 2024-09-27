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


vector<int> digitize(int n, vector<int> rslt) {
    while (n != 0) {
        rslt.pb(n % 10);
        n /= 10;
    }
    return rslt;
}



int main() {
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[n] = 0;
    for (int i = n; i > 0; i--) {
        if (dp[i] == 1e9) {
            continue;
        }
        vector<int> digits;
        digits = digitize(i, digits);
        for (int j = 0; j < sz(digits); j++) {
            if (i - digits[j] < 0) {
                continue;
            }
            dp[i - digits[j]] = min(dp[i - digits[j]], dp[i] + 1);
        }
    }
    cout << dp[0] << '\n';
}