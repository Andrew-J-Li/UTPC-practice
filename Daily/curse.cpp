#include <bits/stdc++.h>
#define endl "\n"
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    for (int a = 0; a < t; ++a) {
        int n, k; cin >> n >> k;
        string s1, s2; cin >> s1 >> s2;
        bool good = true;
        if (n <= 5) {
            if (n <= 3) {
                for (int i = 0; i < n; ++i) {
                    if (s1[i] != s2[i]) good = false;
                }
            } else if (n == 4) {
                vector<int> fr (26);
                fr[s1[0] - 'a']++; fr[s2[0] - 'a']--;
                fr[s1[3] - 'a']++; fr[s2[3] - 'a']--;
                for (int i = 1; i < n - 1; ++i) {
                    if (s1[i] != s2[i]) good = false;
                }
                for (int i = 0; i < 26; ++i) if (fr[i] != 0) good = false;
            } else if (n == 5) {
                vector<int> fr (26);
                if (s1[2] != s2[2]) good = false;
                for (int i = 0; i < n; ++i) {
                    if (i == 2) continue;
                    fr[s1[i] - 'a']++; fr[s2[i] - 'a']--;
                }
                for (int i : fr) if (i != 0) good = false;
            }
        } else {
            vector<int> fr (26);
            for (int i = 0; i < s1.size(); ++i) {
                fr[s1[i] - 'a']++;
                fr[s2[i] - 'a']--;
            }
            for (int i = 0; i < 26; ++i) {
                if (fr[i] != 0) good = false;
            }
        }
        if (good) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}