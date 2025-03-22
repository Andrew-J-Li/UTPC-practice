#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int a = 0; a < t; a++) {
        int n; cin >> n;
        vector<int> mex (n);
        for (int i = 0; i < n; i++) {
            cin >> mex[i];
        }
        vector<pair<int, int>> rslt;
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (mex[i] == 0) {
                if (i == n - 1) rslt.push_back({i - c, i + 1 - c});
                else rslt.push_back({i + 1 - c, i + 2 - c});
                c++;
                i++;
            }
        }
        cout << rslt.size() + 1 << endl;
        for (pair<int, int> p : rslt) {
            cout << p.first << " " << p.second << endl;
        }
        cout << 1 << " " << n - c << endl;
    }
}