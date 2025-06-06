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
        ll n; cin >> n;
        vector<ll> nums (2 * n);
        for (ll i = 0; i < 2 * n; ++i) cin >> nums[i];
        sort(nums.begin(), nums.end());
        ll target = nums[(2 * n) - 1];
        for (ll i = (2 * n) - 2; i >= 0; --i) target += ((i & 1) ? -nums[i] : nums[i]);
        cout << nums[(2 * n) - 1] << " " << target << " ";
        for (ll i = 0; i < (2 * n) - 1; ++i) cout << nums[i] << " ";
        cout << endl;
    }
    return 0;
}