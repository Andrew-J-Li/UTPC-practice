#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, a, b, c, t;
    cin >> n >> a >> b >> c >> t;
    ll rslt = 0;
    for (ll i = 0; i < n; ++i) {
        ll curr; cin >> curr;
        if (a + (c - b) * (t - curr) > a) rslt += a + (c - b) * (t - curr);
        else rslt += a;
    }
    cout << rslt << endl;
}