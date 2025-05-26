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
        int n, k; cin >> n >> k;
        string s; cin >> s;
        pair<int, int> o = {0, 0};
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') o.first++;
            else o.second++;
        }
        while (k != 0) {
            if (o.first >= o.second) o.first -= 2;
            else o.second -= 2;
            k--;
        }
        if (o.first < 0 || o.second < 0 || o.first != o.second) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}