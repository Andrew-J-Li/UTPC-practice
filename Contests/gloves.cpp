#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    for (ll a = 0; a < t; ++a) {
        ll n, k; cin >> n >> k;
        vector<ll> top (n);
        vector<ll> bot (n);
        vector<ll> gloves(n);
        ll rslt = 0;
        for (ll i = 0; i < n; ++i) cin >> top[i];
        for (ll i = 0; i < n; ++i) cin >> bot[i];
        for (ll i = 0; i < n; ++i) {
            gloves[i] = min(top[i], bot[i]);
            rslt += max(top[i], bot[i]);
        }

        sort(gloves.begin(), gloves.end(), greater<ll>());
        for (ll i = 0; i < k - 1; ++i) {
            rslt += gloves[i];
        }
        rslt++;
        cout << rslt << endl;
    }
}