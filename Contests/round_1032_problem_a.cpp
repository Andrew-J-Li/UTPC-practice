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
        ll n, s; cin >> n >> s;
        ll mn = LLONG_MAX, mx = LLONG_MIN;
        for (ll i = 0; i < n; ++i) {
            ll temp; cin >> temp;
            mn = min(mn, temp);
            mx = max(mx, temp);
        }
        cout << min(abs(s - mx), abs(s - mn)) + mx - mn << endl;
    }
    return 0;
}