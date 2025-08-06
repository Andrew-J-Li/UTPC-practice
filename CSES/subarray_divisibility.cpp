#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    vector<ll> nums (n);
    for (ll i = 0; i < n; ++i) cin >> nums[i];

    ll curr = 0, rslt = 0;
    map<ll, ll> mp;
    mp[0]++;
    for (ll i = 0; i < n; ++i) {
        curr += nums[i];
        curr %= n;
        rslt += mp[((curr < 0) ? n + curr : curr)];
        mp[((curr < 0) ? n + curr : curr)]++;
    }

    cout << rslt << endl;
    return 0;
}