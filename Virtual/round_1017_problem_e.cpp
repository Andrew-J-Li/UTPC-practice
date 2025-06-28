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
        vector<ll> ct (30);
        vector<ll> nums (n);
        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            ll temp; cin >> temp;
            nums[i] = temp;
            sum += temp;
            ll curr = 0;
            while (curr < 30) {
                if (temp & (1 << curr)) ct[curr]++;
                curr++;
            }
        }
        ll rslt = 0;
        for (ll i = 0; i < n; ++i) {
            ll temp_rslt = sum;
            for (ll j = 0; j < 30; ++j) {
                if (nums[i] & (1 << j)) {
                    temp_rslt -= ct[j] * (1 << j);
                    temp_rslt += (n - ct[j]) * (1 << j);
                }
            }
            rslt = max(rslt, temp_rslt);
        }
        cout << rslt << endl;
    }
    return 0;
}