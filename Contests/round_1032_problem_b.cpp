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
        vector<vector<ll>> let (n, vector<ll> (26));
        for (ll i = 0; i < n; ++i) {
            if (i != 0) let[i] = let[i - 1];
            let[i][s[i] - 'a']++;
        }
        bool rslt = false;
        for (ll i = 1; i < n - 1; ++i) {
            if (let[i][s[i] - 'a'] > 1 || let[n - 1][s[i] - 'a'] - let[i][s[i] - 'a'] > 0) rslt = true;
        }
        if (rslt) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}