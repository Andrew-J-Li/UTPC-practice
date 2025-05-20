#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; int q; cin >> n >> q;
    vector<vector<bool>> grid (2, vector<bool> (n));
    int ct = 0;
    for (int i = 0; i < q; ++i) {
        int x, y; cin >> x >> y; x--; y--;
        if (!grid[x][y]) {
            grid[x][y] = true;
            if (y + 1 < n && grid[(x == 0) ? 1 : 0][y + 1]) ct++;
            if (grid[(x == 0) ? 1 : 0][y]) ct++;
            if (y - 1 >= 0 && grid[(x == 0) ? 1 : 0][y - 1]) ct++;
            if (ct > 0) cout << "No" << endl;
            else cout << "Yes" << endl;
        } else {
            grid[x][y] = false;
            if (y + 1 < n && grid[(x == 0) ? 1 : 0][y + 1]) ct--;
            if (grid[(x == 0) ? 1 : 0][y]) ct--;
            if (y - 1 >= 0 && grid[(x == 0) ? 1 : 0][y - 1]) ct--;
            if (ct > 0) cout << "No" << endl;
            else cout << "Yes" << endl;
        }
    }
}