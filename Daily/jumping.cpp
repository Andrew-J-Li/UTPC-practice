#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    string l, r; cin >> l >> r;
    vector<vector<vector<pair<int, int>>>> adj (2, vector<vector<pair<int, int>>> (n + 1));
    for (int i = 0; i < n; ++i) {
        if (l[i] == '-') {
            if (i + 1 < n && l[i + 1] == '-') {
                adj[0][i].push_back({0, i + 1});
                adj[0][i + 1].push_back({0, i});
            } else if (i + 1 >= n) adj[0][i].push_back({0, n});
            if (i + k < n && r[i + k] == '-') adj[0][i].push_back({1, i + k});
            else if (i + k >= n) adj[0][i].push_back({0, n});
        }
        if (r[i] == '-') {
            if (i + 1 < n && r[i + 1] == '-') {
                adj[1][i].push_back({1, i + 1});
                adj[1][i + 1].push_back({1, i});
            } else if (i + 1 >= n) adj[1][i].push_back({0, n});
            if (i + k < n && l[i + k] == '-') adj[1][i].push_back({0, i + k});
            else if (i + k >= n) adj[1][i].push_back({0, n});
        }
    }

    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<int>> dist (2, vector<int> (n + 1, INT_MAX));
    dist[0][0] = 0;
    pq.push({0, {0, 0}});
    while (!pq.empty()) {
        pair<int, pair<int, int>> temp = pq.top();
        int step = temp.first; pair<int, int> loc = temp.second;
        pq.pop();
        for (pair<int, int> curr : adj[loc.first][loc.second]) {
            if (step + 1 < dist[curr.first][curr.second] && curr.second > step) {
                pq.push({step + 1, {curr.first, curr.second}});
                dist[curr.first][curr.second] = step + 1;
            }
        }
    }
    if (dist[0][n] == INT_MAX) cout << "NO" << endl;
    else cout << "YES" << endl;
}