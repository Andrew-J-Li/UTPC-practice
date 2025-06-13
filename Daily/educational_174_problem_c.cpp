#include <bits/stdc++.h>
#define endl "\n"
#define MOD 998244353LL
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        vector<vector<ll>> dp (n, vector<ll> (4));
        for (ll i = 0; i < n; ++i) {
            dp[i][1] = (i == 0) ? 0 : dp[i - 1][1];
            if (nums[i] == 1) dp[i][1] = (dp[i][1] + 1) % MOD;
            dp[i][2] = (i == 0) ? 0 : dp[i - 1][2];
            if (nums[i] == 2) dp[i][2] = (2LL * dp[i][2] + dp[i][1]) % MOD;
            dp[i][3] = (i == 0) ? 0 : dp[i - 1][3];
            if (nums[i] == 3) dp[i][3] = (dp[i][3] + dp[i][2]) % MOD;
        }
        cout << dp[n - 1][3] << endl;
    }
    return 0;
}