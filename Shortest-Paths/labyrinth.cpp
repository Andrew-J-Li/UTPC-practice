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
    pair<int, int> start, end;
    for (int i = 0; i < n; ++i) {
        cin >> grid[i];
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'A') {
                start.first = i;
                start.second = j;
            }
            if (grid[i][j] == 'B') {
                end.first = i;
                end.second = j;
            }
        }
    }

    vector<vector<char>> track (n, vector<char> (m));
    vector<vector<int>> weight (n, vector<int> (m, INT_MAX));
    vector<vector<bool>> visited (n, vector<bool> (m));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<pair<int, int>> dirs {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    pq.push({0, start});
    while (!pq.empty()) {
        pair<int, pair<int, int>> curr = pq.top();
        pq.pop();
        int dist = curr.first;
        pair<int, int> loc = curr.second;
        visited[loc.first][loc.second] = true;
        if (loc.first == end.first && loc.second == end.second) break;

        for (pair<int, int> i : dirs) {
            if (loc.first + i.first >= 0 && loc.first + i.first < n && loc.second + i.second >= 0 && loc.second + i.second < m) {
                if (grid[loc.first + i.first][loc.second + i.second] != '#') {
                    if (dist + 1 < weight[loc.first + i.first][loc.second + i.second]) {
                        weight[loc.first + i.first][loc.second + i.second] = dist + 1;
                        pq.push({dist + 1, {loc.first + i.first, loc.second + i.second}});
                        if (i.first == -1) track[loc.first + i.first][loc.second + i.second] = 'U';
                        if (i.first == 1) track[loc.first + i.first][loc.second + i.second] = 'D';
                        if (i.second == -1) track[loc.first + i.first][loc.second + i.second] = 'L';
                        if (i.second == 1) track[loc.first + i.first][loc.second + i.second] = 'R';
                    }
                }
            }
        }
    }

    if (weight[end.first][end.second] != INT_MAX) {
        cout << "YES" << endl;
        cout << weight[end.first][end.second] << endl;
        pair<int, int> curr = end;
        vector<char> rslt;
        while (!(curr.first == start.first && curr.second == start.second)) {
            rslt.push_back(track[curr.first][curr.second]);
            char test = track[curr.first][curr.second];
            if (test == 'U') curr.first++;
            else if (test == 'D') curr.first--;
            else if (test == 'L') curr.second++;
            else curr.second--;
        }
        for (int i = rslt.size() - 1; i >= 0; --i) {
            cout << rslt[i];
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }
}