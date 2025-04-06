#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main() {
    ll n, d; cin >> n >> d;
    vector<pair<ll, ll>> th (n);
    map<ll, ll> go;
    for (ll i = 0; i < n; ++i) {
        cin >> th[i].first >> th[i].second;
        go[th[i].first] = i;
    }
    sort(th.begin(), th.end());
    vector<ll> dp (n + 1);
    for (ll i = 0; i < n; ++i) {
        auto it = go.lower_bound(th[i].first + d);
        ll idx = (it == go.end()) ? n : it->second;
        dp[i] = (i == 0) ? dp[i] : max (dp[i], dp[i - 1]);
        dp[idx] = max(dp[idx], th[i].second + dp[i]);
    }
    cout << dp[n] << endl;
}