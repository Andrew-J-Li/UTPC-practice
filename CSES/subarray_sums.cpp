#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, x; cin >> n >> x;
    vector<ll> ps (n);
    cin >> ps[0];
    for (ll i = 1; i < n; ++i) {
        cin >> ps[i];
        ps[i] += ps[i - 1];
    }
    ll rslt = 0;
    map<ll, ll> mp;
    mp[0]++;
    for (ll i = 0; i < n; ++i) {
        if (mp.count(ps[i] - x)) rslt += mp[ps[i] - x];
        mp[ps[i]]++;
    }

    cout << rslt << endl;
    return 0;
}