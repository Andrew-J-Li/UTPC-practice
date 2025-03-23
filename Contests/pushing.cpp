#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int a = 0; a < t; a++) {
        int n, m;
        cin >> n >> m;
        vector<string> grid (n);
        for (int i = 0; i < n; ++i) {
            cin >> grid[i];
        }

        vector<int> csum (m);
        vector<int> rsum (n);
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    if (csum[j] != i && rsum[i] != j) {
                        bad = true;
                        break;
                    }
                    csum[j]++;
                    rsum[i]++;
                }
            }
            if (bad) break;
        }

        if (bad) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}