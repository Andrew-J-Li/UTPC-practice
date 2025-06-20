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
            ll mid = (lo + hi) / 2;
            cout << "? " << 1 << " " << mid << endl;
            cout.flush();
            ll ans; cin >> ans;
            if (ans == -1) return 0;
            if (ans == mid) {
                rslt = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << "! " << rslt + 1 << endl;
        cout.flush();
    }
    return 0;
}