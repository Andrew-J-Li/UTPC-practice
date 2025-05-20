#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        ll rslt = -1;
        for (ll i = 0; i < n; ++i) {
            if (i + 1 < n && s.substr(i, 2) == "aa") rslt = (rslt == -1) ? 2 : min(rslt, (ll) 2);
            if (i + 2 < n && (s.substr(i, 3) == "aca" || s.substr(i, 3) == "aba")) rslt = (rslt == -1) ? 3 : min(rslt, (ll) 3);
            if (i + 3 < n && (s.substr(i, 4) == "abca" || s.substr(i, 4) == "acba")) rslt = (rslt == -1) ? 4 : min(rslt, (ll) 4);
            if (i + 6 < n && (s.substr(i, 7) == "abbacca" || s.substr(i, 7) == "accabba")) rslt = (rslt == -1) ? 7 : min(rslt, (ll) 7);
        }
        cout << rslt << endl;
    } 
}