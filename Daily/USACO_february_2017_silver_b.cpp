#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);

    ll n, k, b; cin >> n >> k >> b;
    vector<ll> signal (n);
    for (ll i = 0; i < b; ++i) {
        ll curr; cin >> curr;
        curr--;
        signal[curr]--;
    }

    vector<ll> pf (n);
    ll rslt = 0;
    for (ll i = 0; i < n; ++i) {
        pf[i] = (i == 0) ? 0 : pf[i - 1];
        pf[i]++;
        pf[i] += signal[i];

        if (i - k < -1) continue;
        if (i - k == -1) rslt = max(rslt, pf[i]);
        else rslt = max (rslt, pf[i] - pf[i - k]);
    }

    cout << k - rslt << endl;
    return 0;
}