#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    for (int a = 0; a < t; ++a) {
        ll n; cin >> n;
        vector<ll> s (n);
        for (ll i = 0; i < n; ++i) cin >> s[i];
        vector<ll> b (n);
        b[0] = s[0];
        ll rslt = 0;
        for (ll i = 1; i < n; ++i) {
            ll curr = 1;
            b[i] = max(b[i - 1], s[i]);
            ll temp = b[i];
            while (s[i] + pow (2, curr - 1) < temp) {
                temp -= pow (2, curr - 1);
                curr++;
            }
            rslt = (s[i] < temp) ? max(curr, rslt) : rslt;
        }
        cout << rslt << endl;
    } 
}