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
        string p; cin >> p;
        vector<vector<ll>> grid (n, vector<ll>(m));
        vector<ll> rows (n);
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                cin >> grid[i][j];
                rows[i] += grid[i][j];
            }
        }
        vector<ll> cols (m);
        for (ll i = 0; i < m; ++i) {
            for (ll j = 0; j < n; ++j) {
                cols[i] += grid[j][i];
            }
        }
        ll x = 0, y = 0;
        for (ll i = 0; i < p.size(); ++i) {
            if (p[i] == 'D') {
                cols[y] -= grid[x][y];
                cols[y] += -rows[x];
                grid[x][y] = -rows[x];
                x++;
            } else {
                rows[x] -= grid[x][y];
                rows[x] += -cols[y];
                grid[x][y] = -cols[y];
                y++;
            }
        }
        grid[x][y] = -rows[x];
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < m; ++j) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}