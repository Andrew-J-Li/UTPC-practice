#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll n, m; 
    cin >> n >> m;
    
    vector<vector<bool>> adj(n, vector<bool>(n, false));
    vector<ll> deg(n, 0);
    
    for (ll i = 0; i < m; ++i) {
        ll a, b; 
        cin >> a >> b;
        a--; b--;
        adj[a][b] = adj[b][a] = true;
        deg[a]++; deg[b]++;
    }
    
    ll operations = 0;
    
    while (true) {
        bool changed = false;
        for (ll i = 0; i < n && !changed; ++i) {
            if (deg[i] > 2) {
                for (ll j = i + 1; j < n; ++j) {
                    if (adj[i][j] && (deg[i] > 2 || deg[j] > 2)) {
                        adj[i][j] = adj[j][i] = false;
                        deg[i]--; deg[j]--;
                        operations++;
                        changed = true;
                        break;
                    }
                }
            }
        }
        
        if (changed) continue;
        for (ll i = 0; i < n && !changed; ++i) {
            if (deg[i] < 2) {
                for (ll j = 0; j < n; ++j) {
                    if (i != j && !adj[i][j] && deg[j] < 2) {
                        adj[i][j] = adj[j][i] = true;
                        deg[i]++; deg[j]++;
                        operations++;
                        changed = true;
                        break;
                    }
                }
                if (!changed) {
                    for (ll j = 0; j < n; ++j) {
                        if (i != j && !adj[i][j]) {
                            adj[i][j] = adj[j][i] = true;
                            deg[i]++; deg[j]++;
                            operations++;
                            changed = true;
                            break;
                        }
                    }
                }
            }
        }
        
        if (!changed) break;
    }
    
    cout << operations << endl;
    return 0;
}