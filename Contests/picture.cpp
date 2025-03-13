#include <bits/stdc++.h>


using namespace std;


int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g (n, vector<int> (m));
    vector<int> row (n);
    vector<int> col (m);

    int rslt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int temp;
            cin >> temp;
            g[i][j] = temp;
            if (temp != 0) {
                row[i]++;
                col[j]++;
            }
        }
    }

    int c = 0, cu = 0;
    bool u = false;
    for (int i = 0; i < n; i++) {
        if (row[i] == m) {
            if (u == false) c++;
            else cu++;
            rslt = max(rslt, c + cu);
            continue;
        }
        if (row[i] == m - 1) {
            if (u == false) {
                u = true;
                c++;
            } else {
                c = cu;
                u = true;
                c++;
                cu = 0;
            }
            rslt = max(rslt, c + cu);
            continue;
        }
        rslt = max(rslt, c + cu);
        c = 0;
        cu = 0;
        u = false;
    }

    c = 0, cu = 0;
    u = false;
    for (int j = 0; j < m; j++) {
        if (col[j] == n) {
            if (u == false) c++;
            else cu++;
            rslt = max(rslt, c + cu);
            continue;
        }
        if (col[j] == n - 1) {

            if (u == false) {
                u = true;
                c++;
            } else {
                c = cu;
                u = true;
                c++;
                cu = 0;
            }
            rslt = max(rslt, c + cu);
            continue;
        }
        rslt = max(rslt, c + cu);
        c = 0;
        cu = 0;
        u = false;
    }

    cout << rslt << endl;
}