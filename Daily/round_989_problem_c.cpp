#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool check_pos (vector<string>& grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) return true;
    if (grid[i][j] == '$') return true;
    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<string> grid (n);
        for (int i = 0; i < n; ++i) cin >> grid[i];
        vector<vector<bool>> visited (n, vector<bool>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (visited[i][j] || grid[i][j] == '?') continue;
                queue<pair<int, int>> q;
                vector<pair<int, int>> path;
                q.push({i, j});
                visited[i][j] = true;
                while (!q.empty()) {
                    auto [ci, cj] = q.front();
                    q.pop();
                    path.push_back({ci, cj});
                    int ni = ci, nj = cj;
                    if (grid[ci][cj] == 'U') ni = ci - 1;
                    else if (grid[ci][cj] == 'D') ni = ci + 1;
                    else if (grid[ci][cj] == 'L') nj = cj - 1;
                    else nj = cj + 1;
                    if (ni < 0 || nj < 0 || ni >= n || nj >= m) {
                        for (auto [pi, pj] : path) grid[pi][pj] = '$';
                        break;
                    }
                    if (grid[ni][nj] == '$') {
                        for (auto [pi, pj] : path) grid[pi][pj] = '$';
                        break;
                    }
                    if (visited[ni][nj] || grid[ni][nj] == '?') break;
                    visited[ni][nj] = true;
                    q.push({ni, nj});
                }
            }
        }
        vector<pair<int, int>> dx = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        ll rslt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '?') {
                    bool adj = true;
                    for (pair<int, int> ch : dx) adj &= check_pos (grid, i + ch.first, j + ch.second);
                    if (adj) grid[i][j] = '$';
                }
                if (grid[i][j] != '$') rslt++;
            }
        }
        cout << rslt << endl;
    }
    return 0;
}