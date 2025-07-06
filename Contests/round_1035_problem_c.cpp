#include <bits/stdc++.h>
#define endl "\n"
#define ll unsigned long long
#define MOD 1000000007LL
using namespace std;

ll find_msb (ll b) {
    ll ct = -1;
    if (b == 0) return ct;
    while (b) {
        ct++;
        b >>= 1;
    }
    return ct;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, l, r, k; cin >> n >> l >> r >> k;
        if (n == 2) { cout << -1 << endl; continue; }
        if (n & 1) { cout << l << endl; continue; }
        ll msb = find_msb(l);
        ll res = (1LL << (msb + 1LL));
        if (res > r) { cout << -1 << endl; continue; }
        if (k > n - 2) { cout << res << endl; }
        else cout << l << endl;
    }
    return 0;
}