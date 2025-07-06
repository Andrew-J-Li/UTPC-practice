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
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        if (n == 1) { cout << "NO" << endl; continue; }

        ll mx = nums[0], res = -1;
        for (ll i = 1; i < n; ++i) {
            if (nums[i] < mx) { res = nums[i]; break; }
            else mx = max(mx, nums[i]);
        }

        if (res == -1) { cout << "NO" << endl; continue; }
        cout << "YES" << endl;
        cout << 2 << endl;
        cout << mx << " " << res << endl;
    }
    return 0;
}