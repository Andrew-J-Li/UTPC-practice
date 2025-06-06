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
        ll n, k; cin >> n >> k;
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        ll lo = 0, hi = n + 1, rslt = -1;
        while (lo <= hi) {
            ll mid = (lo + hi) / 2, target = (mid * (mid + 1)) / 2;
            ll count = 0, sum = 0;
            vector<bool> v (mid + 1);
            for (ll i = 0; i < n; ++i) {
                if (nums[i] >= v.size() || v[nums[i]]) continue;
                v[nums[i]] = true;
                sum += nums[i];
                if (v[0] && sum == target) {
                    count++;
                    fill(v.begin(), v.end(), false);
                    sum = 0;
                }
            }
            if (count >= k) {
                rslt = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        cout << rslt + 1 << endl;
    } 
    return 0;
}