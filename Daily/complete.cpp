#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    int lo = 0, hi = 0;
    vector<int> letters (26);
    bool good = true;
    bool finished = false;

    while (lo <= hi && hi <= s.size()) {
        if (!good) {
            if (s[lo] == '?') {
                lo++;
                continue;
            }
            if (letters[s[lo] - 'A'] == 2) good = true;
            letters[s[lo] - 'A']--;
            lo++;
            continue;
        }
        if (hi - lo < 26) {
            if (s[hi] == '?') {
                hi++;
                continue;
            }
            letters[s[hi] - 'A']++;
            if (letters[s[hi] - 'A'] > 1) good = false;
            hi++;
            continue;
        }
        finished = true;
        for (int i = lo; i < hi; ++i) {
            if (s[i] == '?') {
                for (int j = 0; j < letters.size(); ++j) {
                    if (!letters[j]) {
                        s[i] = 'A' + j;
                        letters[j] = true;
                        break;
                    }
                }
            }
        }
        break;
    }
    for (int i = 0; i < s.size(); ++i) if (s[i] == '?') s[i] = 'A';
    if (finished) cout << s << endl;
    else cout << -1 << endl;
}