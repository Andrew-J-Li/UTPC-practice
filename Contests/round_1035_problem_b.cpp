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
        pair<ll, ll> p, q;
        cin >> p.first >> p.second >> q.first >> q.second;
        vector<ll> ops (n);
        for (ll i = 0; i < n; ++i) cin >> ops[i];
        sort (ops.begin(), ops.end(), greater<ll>());
        cout << ops[0] << endl;
    }
    return 0;
}