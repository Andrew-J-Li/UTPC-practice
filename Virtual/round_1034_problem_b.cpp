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
        ll n, j, k; cin >> n >> j >> k;
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        if (k != 1) { cout << "YES" << endl; continue; }
        ll mx = -1;
        for (ll i = 0; i < n; ++i) mx = max(nums[i], mx);
        if (nums[j - 1] == mx) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}