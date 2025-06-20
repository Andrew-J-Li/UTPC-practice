#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll gcd (ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, a, b; cin >> n >> a >> b;
        ll d = gcd (a, b);
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];
            nums[i] %= d;
        }
        sort(nums.begin(), nums.end());
        ll rslt = nums[n - 1] - nums[0];
        for (ll i = 1; i < n; ++i) {
            rslt = min(rslt, nums[i - 1] + d - nums[i]);
        }
        cout << rslt << endl;
    }
    return 0;
}