#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int a = 0; a < t; a++) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        int rslt = INT_MAX;
        for (int i = 0; i <= s.size() - k; i++) {
            string x = "RGB";
            vector<int> curr {0, 1, 2};
            vector<int> temp (3);
            for (int j = i; j < i + k; j++) {
                for (int l = 0; l < 3; l++) {
                    if (s[j] != x[curr[l]]) temp[l]++;
                    if (curr[l] == 2) curr[l] = 0;
                    else curr[l]++;
                }
            }
            rslt = min(rslt, min(min(temp[1], temp[0]), temp[2]));
        }

        cout << rslt << endl;
    }
}