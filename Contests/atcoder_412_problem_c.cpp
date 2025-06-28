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
        ll start = nums[0], end = nums[n - 1];
        sort (nums.begin(), nums.end());
        ll rslt = 1;
        ll prev = start, up = -1;
        for (ll i = 1; i < n; ++i) {
            if (nums[i] <= 2 * prev) up = nums[i];
            else {
                prev = up;
                rslt++;
                if (nums[i] <= 2 * prev) up = nums[i];
                else { rslt = -1; break; }
            }
            if (up >= end) break;
        }
        if (rslt == -1) cout << rslt << endl;
        else cout << rslt + 1 << endl;
    }
    return 0;
}