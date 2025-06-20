#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll lo = 2, hi = 999;
        ll rslt = 1;
        while (lo <= hi) {
            ll mid1 = lo + (hi - lo) / 3;
            ll mid2 = hi - (hi - lo) / 3;
            cout << "? " << mid1 << " " << mid2 << endl;
            cout.flush();
            ll ans; cin >> ans;
            if (ans == -1) return 0;
            if (ans == mid1 * mid2) {
                rslt = mid2;
                lo = mid2 + 1;
            } else if (ans == mid1 * (mid2 + 1)){
                rslt = mid1;
                lo = mid1 + 1;
                hi = mid2 - 1;
            } else {
                hi = mid1 - 1;
            }
        }
        cout << "! " << rslt + 1 << endl;
        cout.flush();
    }
    return 0;
}