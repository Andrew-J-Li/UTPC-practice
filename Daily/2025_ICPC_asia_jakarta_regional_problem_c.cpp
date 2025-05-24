#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t; cin >> s >> t;
    vector<int> pf (26, INT_MAX);
    for (int i = t.size() - 2; i >= 0; --i) {
        pf[t[i] - 'a'] = min(pf[t[i] - 'a'], (int) t.size() - i);
    }
    vector<bool> v (26);
    int len = INT_MAX; string rslt;
    for (int i = 1; i < s.size(); ++i) {
        if (pf[s[i] - 'a'] == INT_MAX || v[s[i] - 'a']) continue;
        if (i + 1 + pf[s[i] - 'a'] < len) {
            rslt = s.substr(0, i) + t.substr(t.size() - pf[s[i] - 'a'], pf[s[i] - 'a']);
            len = i + 1 + pf[s[i] - 'a'];
            v[s[i] - 'a'] = true;
        }
    }
    if (len == INT_MAX) cout << -1 << endl;
    else cout << rslt << endl;
    return 0;
}