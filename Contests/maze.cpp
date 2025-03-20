#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<string> maze (n);
    pair<int, int> start = {-1, -1};

    int s = 0;
    for (int i = 0; i < n; i++) {
        cin >> maze[i];
        for (int j = 0; j < m; j++) {
            if (start.first == -1 && maze[i][j] == '.') {
                start.first = i;
                start.second = j;
            }
            if (maze[i][j] == '.') s++;
        }
    }

    set<pair<int, int>> points;
    queue<pair<int, int>> q;
    q.push(start);
    points.insert(start);
    int t = 1;
    while (t < s - k) {
        pair<int, int> curr = q.front();
        bool done = false;
        q.pop();

        for (int dx = -1; dx <= 1; dx++) {
            if (points.count({curr.first + dx, curr.second}) != 0) continue;
            if (curr.first + dx < 0 || curr.first + dx >= n) continue;
            if (maze[curr.first + dx][curr.second] == '#') continue;
            q.push({curr.first + dx, curr.second});
            points.insert({curr.first + dx, curr.second});
            t++;
            if (t >= s - k) {
                done = true;
                break;
            }
        }

        if (done) break;

        for (int dy = -1; dy <= 1; dy++) {
            if (points.count({curr.first, curr.second + dy}) != 0) continue;
            if (curr.second + dy < 0 || curr.second + dy >= m) continue;
            if (maze[curr.first][curr.second + dy] == '#') continue;
            q.push({curr.first, curr.second + dy});
            points.insert({curr.first, curr.second + dy});
            t++;
            if (t >= s - k) {
                done = true;
                break;
            }
        }

        if (done) break;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (points.count({i, j}) == 0 && maze[i][j] == '.') maze[i][j] = 'X';
        }
        cout << maze[i] << endl;
    }
}