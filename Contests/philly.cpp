#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> kur (n), tfg (n);
    for (int i = 0; i < n; ++i) cin >> kur[i];
    for (int i = 0; i < n; ++i) cin >> tfg[i];
    vector<vector<int>> adj (n);
    for (int i = 0; i < n - 1; ++i) {
        int t1, t2; cin >> t1 >> t2;
        adj[t1 - 1].push_back(t2 - 1);
    }
    queue<int> q;
    q.push(0);
    q.push(0);
    q.push(0);
    vector<pair<int, int>> (n);
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        int turn = q.front();
        q.pop();
        int kuroni = q.front();
        q.pop();
        int tfg = q.front();
        q.pop();
        if (turn == 0)
        if (kur[curr]) kuroni++;
    }
}