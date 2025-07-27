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

    unordered_map<ll, ll> mp;
    for (ll i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            n /= i;
            mp[i]++;
        }
    }
    if (n != 1) mp[n]++;

    ll rslt = 0;
    for (const auto& it : mp) {
        ll sub = 1, ct = it.second;
        while (ct > 0) {
            ct -= sub;
            if (ct >= 0) rslt++;
            sub++;
        }
    }

    cout << rslt << endl;
    return 0;
}