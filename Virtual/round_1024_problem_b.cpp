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
        ll ct = 0;
        for (ll i = 1; i < n; ++i) {
            cin >> nums[i];
            if (abs(nums[i]) > abs(nums[0])) ct++;
        }
        if (ct >= n / 2 || n - ct - 1 == n / 2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}