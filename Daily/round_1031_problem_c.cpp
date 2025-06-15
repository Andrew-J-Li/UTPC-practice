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
        ll n, m, k; cin >> n >> m >> k;
        vector<string> grid (n);
        for (ll i = 0; i < n; ++i) cin >> grid[i];
        ll rslt = 0;
        vector<vector<ll>> psum (n + 1, vector<ll> (m + 1));
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= m; ++j) {
                psum[i][j] = psum[i - 1][j] + psum[i][j - 1] - psum[i - 1][j - 1];
                if (grid[i - 1][j - 1] == 'g') {
                    rslt++;
                    psum[i][j]++;
                }
            }
        }
        ll mn = LLONG_MAX;
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] != '.') continue;
                ll a = i + 1 - (k - 1), b = j + 1 - (k - 1);
                a = max(1LL, a), b = max(1LL, b);
                ll A = i + 1 + (k - 1), B = j + 1 + (k - 1);
                A = min(n, A), B = min(m, B);
                ll gold = psum[A][B] - psum[a - 1][B] - psum[A][b - 1] + psum[a - 1][b - 1];
                mn = min(mn, gold);
            }
        }
        if (mn == LLONG_MAX) { cout << 0 << endl; continue; }
        cout << rslt - mn << endl;
    } 
    return 0;
}