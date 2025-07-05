#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        s = '0' + s;
        char curr = s[0];
        ll seg = 0;
        for (ll i = 1; i <= n; ++i) {
            if (s[i] != curr) {
                seg++;
                curr = s[i];
            }
        }
        ll rslt = 0;
        if (seg >= 2) rslt--;
        if (seg >= 3) rslt--;
        curr = '0';
        for (ll i = 1; i <= n; ++i) {
            rslt++;
            if (s[i] != curr) {
                rslt++;
                curr = s[i];
            }
        }
        cout << rslt << endl;
    }
    return 0;
}