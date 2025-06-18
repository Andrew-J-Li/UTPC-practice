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
        ll sum = (n * (n + 1)) / 2;
        ll u = 0;
        ll curr = 1;
        for (ll i = 2; i <= n; ++i) {
            if (s[i - 1] == '0') { curr++; continue; }
            if (curr >= 1) { u++; curr--; }
            else curr++;
        }
        for (ll i = n - 1; i >= 0; --i) {
            if (u <= 0) break;
            if (s[i] == '1') { sum -= i + 1; u--; }
        }
        cout << sum << endl;
    }
    return 0;
}