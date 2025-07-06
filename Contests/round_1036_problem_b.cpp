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
        vector<pair<ll, pair<ll, ll>>> pf (n, {0, {LLONG_MAX, 0}});
        for (ll i = 0; i < n; ++i) {
            if (i != 0) pf[i] = pf[i - 1];
            if (nums[i] < pf[i].second.first) {
                pf[i].second.first = nums[i];
                pf[i].second.second++;
            }
            pf[i].first += pf[i].second.first;
        }
        ll rslt = pf[n - 1].first;
        for (ll i = 1; i < n; ++i) {
            ll curr = pf[i - 1].first;
            if (pf[i - 1].second.second == i) curr += nums[i];
            rslt = min(rslt, curr);
        }
        cout << rslt << endl;
    }
    return 0;
}