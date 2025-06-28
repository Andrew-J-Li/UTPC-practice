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
        vector<ll> nums (2 * n, -1);
        ll sum = 0, target = (2 * n + 1) * (2 * n) / 2;
        for (ll i = 1; i <= n; ++i) {
            for (ll j = 1; j <= n; ++j) {
                ll temp; cin >> temp;
                if (nums[i + j - 1] != -1) continue;
                nums[i + j - 1] = temp;
                sum += temp;
            }
        }
        nums[0] = target - sum;
        for (ll it : nums) cout << it << " ";
        cout << endl;
    }
    return 0;
}