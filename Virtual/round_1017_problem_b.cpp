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
        ll n, m, l, r;
        cin >> n >> m >> l >> r;
        if (l + (n - m) <= 0) cout << l + (n - m) << " " << r << endl;
        else cout << 0 << " " << r - (n - m + l) << endl;
    }
    return 0;
}