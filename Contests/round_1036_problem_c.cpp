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
        vector<ll> bad;
        ll mn = nums[n - 1];
        for (ll i = n - 2; i >= 0; --i) {
            if (nums[i] > mn || nums[i + 1] % nums[i] != 0) bad.push_back(nums[i]);
            mn = min(nums[i], mn);
        }
        if (bad.empty()) { cout << 1 << endl; continue; }
        sort (bad.begin(), bad.end());
        vector<ll> divisors;
        for (int i = 1; i * i <= bad[0]; ++i) {
            if (bad[0] % i == 0) {
                divisors.push_back(i);
                if (i != bad[0] / i) divisors.push_back(bad[0] / i);
            }
        }
        ll rslt = 1;
        for (ll i = 0; i < divisors.size(); ++i) {
            if (divisors[i] == 1) continue;
            bool valid = true;
            mn = nums[n - 1]; ll fac = divisors[i];
            vector<bool> op (n);
            for (ll j = n - 2; j >= 0; --j) {
                ll nx = (op[j + 1]) ? (nums[j + 1] / fac) : nums[j + 1];
                if (nums[j] > mn || nx % nums[j] != 0) {
                    if ((nums[j] / fac) > mn || (nums[j] / fac) == 0 || nx % (nums[j] / fac) != 0) {
                        valid = false;
                        break;
                    }
                    op[j] = true;
                }
                mn = min (mn, ((op[j]) ? (nums[j] / fac) : nums[j]));
            }
            if (valid) { rslt = fac; break; }
        }
        cout << rslt << endl;
    }
    return 0;
}