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
        ll mn = LLONG_MAX, mx = LLONG_MIN;
        vector<ll> pmin (n);
        vector<ll> pmax (n);
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];

            mn = min (mn, nums[i]);
            pmin[i] = mn;
        }
        for (ll i = n - 1; i >= 0; --i) {
            mx = max (mx, nums[i]);
            pmax[i] = mx;
        }
        for (ll i = 0; i < n; ++i) {
            ll cmin = (i == 0) ? LLONG_MAX : pmin[i - 1];
            ll cmax = (i == n - 1) ? LLONG_MIN : pmax[i + 1];
            if (nums[i] <= cmin || nums[i] >= cmax) cout << 1;
            else cout << 0;
        }
        cout << endl;
    }
    return 0;
}