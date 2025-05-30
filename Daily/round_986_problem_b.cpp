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
        ll n, b, c; cin >> n >> b >> c;
        if (b == 0) {
            if (c >= n) cout << n << endl;
            else if (c >= n - 2) cout << n - 1 << endl;
            else cout << -1 << endl;
        } else {
            if (c >= n) cout << n << endl;
            else cout << n - max((ll) 0, 1 + (n - c - 1) / b) << endl;
        }
    }
    return 0;
}