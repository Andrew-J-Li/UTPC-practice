#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        string s; cin >> s;
        vector<ll> ps (n);
        for (ll i = 0; i < n; ++i) {
            ps[i] = (i == 0) ? 0 : ps[i - 1];
            ps[i] += (s[i] - '0') - 1;
        }

        map<ll, ll> mp;
        ll rslt = 0;
        mp[0]++;
        for (ll i = 0; i < n; ++i) {
            rslt += mp[ps[i]];
            mp[ps[i]]++;
        }
        cout << rslt << endl;
    }
    return 0;
}