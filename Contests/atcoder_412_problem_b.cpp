#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;
    unordered_set<char> u_set;
    for (char c : t) u_set.insert(c);
    bool valid = true;
    for (ll i = 1; i < (ll) s.size(); ++i) {
        if (tolower(s[i]) != s[i]) {
            if (u_set.count(s[i - 1]) == 0) {
                valid = false;
                break;
            }
        }
    }
    if (valid) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}