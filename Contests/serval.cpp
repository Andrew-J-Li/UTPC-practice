#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int n, k;
        string s;
        cin >> n >> k >> s;

        bool good = false;
        bool same_let = true;

        int i = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == s[(n - 1) - i]) continue;
            if (s[i] < s[(n - 1) - i]) {
                good = true;
                break;
            } else {
                good = false;
                break;
            }
        }

        for (int i = 1; i < s.size(); i++) {
            if (s[i] != s[i - 1]) same_let = false;
        }

        if (good) cout << "YES" << endl;
        else {
            if (k == 0) cout << "NO" << endl;
            else if (same_let) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
    }
}