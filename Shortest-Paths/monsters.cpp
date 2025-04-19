#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<string> grid (n);
    vector<pair<int, int>> mons;
    vector<pair<int, int>> exits;
    pair<int, int> start;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') mons.push_back({i, j});
            if (grid[i][j] == 'A') start = {i, j};
        }
    }

    vector<vector<int>> human_dist(n, vector<int> (m, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> human;
    human.push({0, start});
    while (!source.empty()) {
        pair<ll, ll> curr = source.top();
        source.pop();
        ll weight = curr.first, loc = curr.second;

        for (ll i : adj[loc]) {
            if (weight + 1 < dist[i]) {
                dist[i] = weight + 1;
                source.push({weight + 1, i});
            }
        }
    }
}