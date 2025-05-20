#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; string s; cin >> n >> s;
        vector<pair<char, int>> seq;
        int prev = -1; int dupe = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] - 'a' >= prev) {
                if (s[i] - 'a' == prev) dupe++;
                else dupe = 0;
                prev = s[i] - 'a';
                seq.push_back({s[i], i});
            }
        }
        for (int i = 0; i < seq.size(); ++i) s[seq[i].second] = seq[seq.size() - 1 - i].first;
        prev = -1; bool bad = false;
        for (int i = 0; i < n; ++i) {
            if (s[i] < prev) {
                bad = true;
                break;
            } else {
                prev = s[i];
            }
        }
        if (bad) cout << -1 << endl;
        else cout << seq.size() - 1 - dupe << endl;
    }
}