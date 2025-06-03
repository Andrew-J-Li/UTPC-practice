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
        ll n, m; cin >> n >> m;
        vector<ll> flowers (n);
        for (ll i = 0; i < n; ++i) cin >> flowers[i];
        vector<ll> beauty (m);
        for (ll i = 0; i < m; ++i) cin >> beauty[i];
        vector<ll> front (n);
        vector<ll> back (n);
        for (ll i = 0; i < n; ++i) {
            front[i] = (i == 0) ? 0 : front[i - 1];
            if (front[i] >= m) continue;
            if (flowers[i] >= beauty[front[i]]) front[i]++;
        }
        for (ll i = n - 1; i >= 0; --i) {
            back[i] = (i == n - 1) ? 0 : back[i + 1];
            if (back[i] >= m) continue;
            if (flowers[i] >= beauty[m - 1 - back[i]]) back[i]++;
        }
        if (front[n - 1] == m) { cout << 0 << endl; continue; }
        ll rslt = LLONG_MAX;
        if (back[0] == m - 1) rslt = min(rslt, beauty[0]);
        for (ll i = 0; i < n - 1; ++i) if (front[i] + back[i + 1] == m - 1) rslt = min(rslt, beauty[front[i]]);
        if (front[n - 1] == m - 1) rslt = min(rslt, beauty[m - 1]);
        if (rslt == LLONG_MAX) cout << -1 << endl;
        else cout << rslt << endl;
    }
    return 0;
}