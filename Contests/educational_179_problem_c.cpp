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
        vector<pair<ll, ll>> nums;
        ll prev = -1, rep = 1;
        for (ll i = 0; i < n; ++i) {
            ll curr; cin >> curr;
            if (curr == prev) rep++;
            else {
                if (prev == -1) { prev = curr; continue; }
                nums.push_back({prev, rep});
                rep = 1;
                prev = curr;
            }
        }
        nums.push_back({prev, rep});
        ll rslt = LLONG_MAX;
        ll curr_idx = 0;
        for (ll i = 0; i < nums.size(); ++i) {
            ll rx = curr_idx + nums[i].second - 1;
            ll val = (curr_idx * nums[i].first) + ((n - 1 - rx) * nums[i].first);
            rslt = min(rslt, val);
        }
        cout << rslt << endl;
    }
    return 0;
}