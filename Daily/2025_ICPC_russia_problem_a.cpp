#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k; cin >> n >> k;
    vector<ll> bonus (n);
    vector<ll> cost (n);
    vector<ll> ps (n);
    for (ll i = 0; i < n; ++i) cin >> bonus[i];
    for (ll i = 0; i < n; ++i) {
        cin >> cost[i];
        ps[i] = (i == 0) ? 0 : ps[i - 1];
        ps[i] += bonus[i] / cost[i];
    }
    vector<ll> rslt;
    ll curr = 0;
    for (ll i = 0; i < n; ++i) {
        if (k > curr + (ps[n - 1] - ((i == 0) ? 0 : ps[i - 1]))) { rslt.push_back(0); continue; }
        if (k <= curr + ps[n - 1] - ps[i]) { rslt.push_back(0); continue; }
        ll nx = k - (curr + ps[n - 1] - ps[i]);
        curr += nx;
        rslt.push_back(nx);
    }
    for (ll i : rslt) cout << i << " ";
    cout << endl;
    return 0;
}