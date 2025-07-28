#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

struct HASH {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(const pair<ll, ll>& p) const {
        uint64_t h = splitmix64(p.first) ^ (splitmix64(p.second) << 1);
        return h;
    }
};

ll gcd (ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        ll d = 0, k = 0;
        unordered_map<pair<ll, ll>, ll, HASH> mp;
        ll rslt[n];
        for (ll i = 0; i < n; ++i) {
            if (s[i] == 'D') d++;
            else k++;
            ll td = d, tk = k;
            if (d == 0) tk = 1;
            else if (k == 0) td = 1;
            else { 
                ll div = gcd (d, k);
                td /= div;
                tk /= div;
            }
            pair<ll, ll> curr = make_pair(td, tk);
            rslt[i] = mp[curr] + 1;
            mp[curr]++;
        }
        for (ll i = 0; i < n; ++i) cout << rslt[i] << " ";
        cout << endl;
    }
    return 0;
}