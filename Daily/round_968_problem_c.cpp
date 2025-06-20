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
        ll n, m; cin >> n >> m;
        ll mex = 0;
        for (ll i = 0; i < n; ++i) {
            ll ct; cin >> ct;
            vector<ll> nums (ct);
            for (ll j = 0; j < ct; ++j) cin >> nums[j];
            sort(nums.begin(), nums.end());
            bool u = false;
            ll prev = -1, curr = 0;
            for (ll j = 0; j < ct; ++j) {
                ll goof = nums[j];
                if (nums[j] == prev) continue;
                if (nums[j] == prev + 1) {
                    curr = nums[j] + ((u) ? 1 : 2);
                    prev++;
                    continue;
                }
                if (!u && nums[j] == prev + 2) {
                    prev += 2;
                    curr = prev + 1;
                    u = true;
                    continue;
                } else if (!u) {
                    curr = prev + 2;
                    break;
                }
                curr = prev + 1;
                break;
            }
            mex = max(mex, curr);
        }
        ll rslt = min (m + 1, mex + 1) * mex;
        if (m > mex) rslt += ((m - mex) * mex) + ((m - mex) * (m - mex + 1)) / 2;
        cout << rslt << endl;
    }
    return 0;
}