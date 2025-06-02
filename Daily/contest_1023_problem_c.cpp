#include <bits/stdc++.h>
#define endl "\n"
#define BOUND 10000000000000LL
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        vector<ll> nums (n);
        ll prev = 0, mx = -BOUND, pos = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];
            prev = max(prev + nums[i], nums[i]);
            mx = max(mx, prev);
            if (s[i] == '0') {
                nums[i] = -BOUND;
                pos = i;
            }
        }
        if (s == string(n, '1')) {
            if (mx != k) cout << "No" << endl;
            else {
                cout << "Yes" << endl;
                for (ll i : nums) cout << i << " ";
                cout << endl;
            }
            continue;
        }
        prev = 0, mx = -BOUND;
        for (ll i = 0; i < n; ++i) {
            prev = max(prev + nums[i], nums[i]);
            mx = max(mx, prev); 
        }
        if (mx > k) { cout << "No" << endl; continue; }
        vector<ll> sums (n);
        for (ll i = 0; i < pos; ++i) {
            if (i == 0) sums[i] = nums[i];
            else sums[i] = max(sums[i - 1] + nums[i], nums[i]);
        }
        for (ll i = n - 1; i > pos; --i) {
            if (i == n - 1) sums[i] = nums[i];
            else sums[i] = max(sums[i + 1] + nums[i], nums[i]);
        }
        ll fi = max(0LL, ((pos == 0) ? 0LL : sums[pos - 1]));
        ll se = max(0LL, ((pos == n - 1) ? 0LL : sums[pos + 1]));
        nums[pos] = k - (fi + se);
        cout << "Yes" << endl;
        for (ll i : nums) cout << i << " ";
        cout << endl;
    }
    return 0;
}