#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;
 
const ll MAX_N = 200000;
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll sieve[MAX_N + 1];
    memset (sieve, 0, sizeof(sieve));
 
    for (ll i = 2; i <= MAX_N; ++i) {
        if (sieve[i] == 0) {
            for (ll j = i; j <= MAX_N; j += i) {
                sieve[j] = i;
            }
        }
    }
 
    ll n; cin >> n;
    unordered_map<ll, pair<pair<ll, ll>, ll>> mp;
 
    for (ll i = 0; i < n; ++i) {
        ll curr; cin >> curr;
        while (curr != 1) {
            ll p = sieve[curr], ct = 0;
            while (curr % p == 0) {
                curr /= p;
                ct++;
            }
            if (mp.count(p) == 0) mp[p].first = {LLONG_MAX, LLONG_MAX};
            mp[p].second++;
            pair<ll, ll>& cmx = mp[p].first;
            if (ct >= cmx.second) continue;
            if (ct < cmx.first) {
                cmx.second = cmx.first;
                cmx.first = ct;
            } else {
                cmx.second = ct;
            }
        }
    }
    
    ll rslt = 1;
    for (const auto& it : mp) {
        if (it.second.second <= n - 2) continue;
        ll val = it.first, curr = 1;
        ll exp = (it.second.second == n - 1) ? it.second.first.first : it.second.first.second;
        while (curr <= exp) {
            rslt *= val;
            curr++;
        }
    }
 
    cout << rslt << endl;
    return 0;
}