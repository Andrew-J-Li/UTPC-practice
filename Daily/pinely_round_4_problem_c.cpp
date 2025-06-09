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
        vector<ll> nums (n);
        ll mean = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];
            mean += nums[i];
        }
        if (mean == 0) { cout << 0 << endl; continue; }
        vector<ll> rslt;
        for (ll i = 0; i < 100; ++i) {
            if (mean % n == 0) mean /= n;
            else mean = (mean / n) + 1;
            rslt.push_back(mean);
            ll t_mean = 0;
            for (ll j = 0; j < n; ++j) {
                nums[j] = abs(nums[j] - mean);
                t_mean += nums[j];
            }
            mean = t_mean;
            if (t_mean == 0) break;
        }
        if (mean != 0) { cout << -1 << endl; continue; }
        cout << rslt.size() << endl;
        for (ll i : rslt) cout << i << " ";
        cout << endl;
    }
    return 0;
}