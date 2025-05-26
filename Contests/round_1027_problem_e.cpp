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
        vector<vector<ll>> adj (n);
        vector<ll> w (n);
        for (ll i = 0; i < n; ++i) cin >> w[i];
        for (ll i = 0; i < n; ++i) {
            ll a, b; cin >> a >> b; a--; b--;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        queue<pair<ll, pair<ll, ll>>> q;
        vector<ll> rslt (n);
        rslt[0] = w[0];
        for (ll i = 0; i < adj[0].size(); ++i) q.push({1, {w[0], 0}});
        while (!q.empty()) {
            pair<ll, pair<ll, ll>> curr = q.front();
            q.pop();
            ll dist = curr.first, odd = curr.second.first, even = curr.second.second;
            
        }
    }
    return 0;
}