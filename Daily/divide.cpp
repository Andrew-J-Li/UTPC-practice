#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n; cin >> n;
    unordered_set<long long> g;
    unordered_map<long long, vector<long long>> adj;
    long long start = -1, tc = 0, m = LONG_MAX;
    for (long long i = 0; i < n; ++i) {
        long long a; cin >> a;
        g.insert(a);
        long long temp = 0, goof = a;
        while (goof % 3 == 0) {
            temp++;
            goof /= 3;
        }
        if (temp == tc && a < start) start = a;
        else if (temp > tc) {
            start = a;
            tc = temp;
        }
        m = min(m, a);
    }
    for (long long a : g) {
        if (g.count(a * 3) != 0) adj[a * 3].push_back(a);
        if (a % 2 == 0 && g.count(a / 2) != 0) adj[a / 2].push_back(a);
    }
    if (start == -1) start = m;
    for (long long i = 0; i < n; ++i) {
        cout << start << " ";
        if (adj[start].size() != 0) start = adj[start][0];
    }
    cout << endl;
}