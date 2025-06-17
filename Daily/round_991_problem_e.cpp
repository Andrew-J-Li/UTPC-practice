#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        string a, b, c; cin >> a >> b >> c;
        vector<vector<ll>> dp (a.size() + 1, vector<ll> (b.size() + 1));
        for (ll i = 0; i <= a.size(); ++i) {
            for (ll j = 0; j <= b.size(); ++j) {
                if (i != 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i - 1] == c[i + j - 1]));
                if (j != 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + (b[j - 1] == c[i + j - 1]));
            }
        }
        cout << c.size() - dp[a.size()][b.size()] << endl;
    }
    return 0;
}