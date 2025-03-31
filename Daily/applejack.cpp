#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        mp[temp]++;
    }
    int ss = 0;
    int sr = 0;
    for (auto& a : mp) {
        ss += a.second / 4;
        sr += a.second / 2;
    }
    int q; cin >> q;
    for (int a = 0; a < q; ++a) {
        string s; cin >> s;
        int v; cin >> v;
        if (s[0] == '+') {
            ss -= mp[v] / 4;
            sr -= mp[v] / 2;
            mp[v]++;
            ss += mp[v] / 4;
            sr += mp[v] / 2;
        } else {
            ss -= mp[v] / 4;
            sr -= mp[v] / 2;
            mp[v]--;
            ss += mp[v] / 4;
            sr += mp[v] / 2;
        }
        if (ss >= 1 && sr >= 4) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}