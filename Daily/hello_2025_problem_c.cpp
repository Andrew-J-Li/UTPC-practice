#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll find_msb (ll n) {
    if (n == 0) return -1;
    ll msb = 0;
    n >>= 1;
    while (n != 0) {
        n >>= 1;
        msb++;
    }
    return msb;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll l, r; cin >> l >> r;
        ll r_msb = find_msb(r);
        ll l_msb = find_msb(l);
        ll add = 0;
        while (r_msb == l_msb) {
            add += (1 << r_msb);
            l -= (1 << l_msb);
            r -= (1 << r_msb);
            r_msb = find_msb(r);
            l_msb = find_msb(l);
        }
        if ((1 << r_msb) - 1 == l) cout << add + (1 << r_msb) << " " << add + (1 << r_msb) + 1 << " " << add + l << endl;
        else cout << add + (1 << r_msb) << " " << add + (1 << r_msb) - 1 << " " << add + l << endl;
    }
    return 0;
}