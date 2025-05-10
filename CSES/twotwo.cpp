#include <bits/stdc++.h>
#define endl "\n"
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll sum = ((n + 1) * n) / 2;
    if (sum % 2 == 1) cout << 0 << endl;
    else {
        vector<ll> dp ((sum / 2) + 1);
        dp[0] = 1;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = dp.size() - 1; j - i >= 0; j--) {
                if (dp[j - i]) dp[j] = (dp[j] + dp[j - i]) % MOD;
            }
        }
        if (!dp[dp.size() - 1]) cout << 0 << endl;
        else cout << (dp[dp.size() - 1] * ((MOD + 1) / 2)) % MOD << endl;
    }
}