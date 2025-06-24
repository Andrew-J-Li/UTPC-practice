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
                if (j == n - 1) continue;
                if (nums[i] + nums[j] > nums[n - 1]) rslt++;
            }
        }
        cout << rslt << endl;
    }
    return 0;
}