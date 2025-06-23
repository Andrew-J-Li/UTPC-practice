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
        ll rslt = 0;
        sort (nums.begin(), nums.end());
        for (ll i = 0; i < n; ++i) {
            for (ll j = i + 1; j < n; ++j) {
                ll curr = nums[i] + nums[j];
                ll lo = 0, hi = n - 1, idx = -1;
                while (lo <= hi) {
                    ll mid = (lo + hi) / 2;
                    if (curr > nums[mid]) {
                        idx = mid;
                        lo = mid + 1;
                    } else {
                        hi = mid - 1;
                    }
                }
                if (nums[i] + nums[idx] < nums[j] || curr + nums[j] <= nums[n - 1]) continue;
                cout << idx << endl;
                rslt += idx - 2;

            }
        }
        cout << rslt << endl;
    }
    return 0;
}