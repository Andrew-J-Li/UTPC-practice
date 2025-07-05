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
        unordered_set<ll> ct;
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        for (ll i = 0; i < n; ++i) ct.insert(nums[i]);
        cout << ct.size() << endl;
    }
    return 0;
}