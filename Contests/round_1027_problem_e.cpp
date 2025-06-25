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
        ll n; cin >> n;
        vector<ll> weights (n);
        for (ll i = 0; i < n; ++i) cin >> weights[i];
        vector<pair<ll, ll>> dp (n, {LLONG_MIN, 0});
        vector<vector<ll>> adj (n);
        for (ll i = 0; i < n - 1; ++i) {
            ll a, b; cin >> a >> b;
            a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        vector<bool> v (n);
        dp[0].first = weights[0];
        dp[0].second = 0;
        v[0] = true;
        queue<pair<ll, ll>> q;
        for (ll i = 0; i < adj[0].size(); ++i) q.push({adj[0][i], 0});
        while (!q.empty()) {
            pair<ll, ll> curr = q.front();
            q.pop();
            if (v[curr.first]) continue;
            ll idx = curr.first, parent = curr.second;
            v[idx] = true;

            ll weight = weights[idx];
            dp[idx].first = max(dp[idx].first, weight - dp[parent].second);
            dp[idx].second = min(dp[idx].second, weight - dp[parent].first);
            for (ll i = 0; i < adj[idx].size(); ++i) q.push({adj[idx][i], idx});
        }
        for (pair<ll, ll> it : dp) cout << it.first << " ";
        cout << endl;
    }
    return 0;
}