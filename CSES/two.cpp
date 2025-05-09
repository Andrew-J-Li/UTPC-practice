#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll sum = ((n + 1) * n) / 2;
    if (sum % 2 == 1) cout << "NO" << endl;
    else {
        vector<bool> dp ((sum / 2) + 1);
        vector<ll> parent ((sum / 2) + 1);
        dp[0] = true;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = dp.size() - 1; j - i >= 0; j--) {
                if (dp[j]) continue;
                if (dp[j - i]) {
                    parent[j] = i;
                    dp[j] = true;
                }
            }
        }
        if (!dp[dp.size() - 1]) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            ll i = dp.size() - 1;
            vector<ll> ans_1;
            while (i != 0) {
                ans_1.push_back(parent[i]);
                i -= parent[i];
            }
            cout << ans_1.size() << endl;
            vector<bool> ans_2 (n + 1);
            for (ll i = 0; i < ans_1.size(); ++i) {
                ans_2[ans_1[i]] = true;
                cout << ans_1[i] << " ";
            }
            cout << endl;
            cout << n - ans_1.size() << endl;
            for (ll i = 1; i < ans_2.size(); ++i) {
                if (!ans_2[i]) cout << i << " ";
            }
            cout << endl;
        }
    }
}