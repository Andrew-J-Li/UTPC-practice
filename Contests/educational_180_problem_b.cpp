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
        cin >> nums[0];
        bool good = false;
        for (ll i = 1; i < n; ++i) {
            cin >> nums[i];
            if (abs(nums[i] - nums[i - 1]) <= 1) good = true;
        }
        if (good) { cout << 0 << endl; continue; }
        if (n == 2) { cout << -1 << endl; continue; }
        ll rslt = LLONG_MAX;
        for (ll i = 0; i < n; ++i) {
            for (ll j = 0; j < n - 1; ++j) {
                if (j == i || j + 1 == i) continue;
                if (nums[j] <= nums[i] + 1 && nums[j + 1] >= nums[i] - 1) rslt = min(rslt, abs(i - j) - ((j < i) ? 1 : 0));
                if (nums[j] >= nums[i] - 1 && nums[j + 1] <= nums[i] + 1) rslt = min(rslt, abs(i - j) - ((j < i) ? 1 : 0));
            }
        }
        if (rslt > n - 1) cout << -1 << endl;
        else cout << rslt << endl;
    } 
    return 0;
}
