#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    ll T; 
    cin >> T;
    
    while (T--) {
        ll n; 
        cin >> n;
        
        vector<vector<ll>> grid(n, vector<ll>(n));
        
        ll x = n / 2;
        ll y = n / 2;
        
        ll dx[] = {0, 1, 0, -1};
        ll dy[] = {1, 0, -1, 0};
        ll dir = 0;
        ll num = 0;
        grid[x][y] = num++;
        ll steps = 1;
        
        while (num < n * n) {
            for (ll i = 0; i < 2; i++) {
                for (ll j = 0; j < steps && num < n * n; j++) {
                    x += dx[dir];
                    y += dy[dir];
                    if (x >= 0 && x < n && y >= 0 && y < n) {
                        grid[x][y] = num++;
                    }
                }
                dir = (dir + 1) % 4;
            }
            steps++;
        }
        
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < n; j++) {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    
    return 0;
}