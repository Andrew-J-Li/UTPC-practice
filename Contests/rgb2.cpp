#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int a = 0; a < t; a++) {
        int n, k; cin >> n >> k;
        string s; cin >> s;
        vector<int> idx = {0, 1, 2};
        string rgb = "RGB";
        vector<int> running (3);
        int rslt = INT_MAX;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                if (s[i] != rgb[(idx[j] + i % 3) % 3]) running[j]++;
            }
            if (i == k - 1) rslt = min(rslt, min(min(running[0], running[1]), running[2]));
            if (i < k) continue;
            for (int j = 0; j < 3; j++) {
                if (s[i - k] != rgb[(idx[j] + (i - k) % 3) % 3]) running[j]--;
            }
            rslt = min(rslt, min(min(running[0], running[1]), running[2]));
        }
        cout << rslt << endl;
    }
}