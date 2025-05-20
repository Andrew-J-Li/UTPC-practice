#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m; cin >> n >> m;
    ll rslt = n;
    vector<unordered_set<ll>> adj (n);
    for (ll i = 0; i < m; ++i) {
        ll a, b; cin >> a >> b;
        if (a < b) {
            if (adj[a].empty()) rslt--;
            adj[a].insert(b);
        } else {
            if (adj[b].empty()) rslt--;
            adj[b].insert(a);
        }
    }
    ll q; cin >> q;
    for (ll i = 0; i < q; ++i) {
        ll a, b, c; cin >> a;
        if (a != 3) cin >> b >> c;
        if (a == 3) cout << rslt << endl;
        else if (a == 1) {
            if (b < c) {
                if (adj[b].empty()) rslt--;
                adj[b].insert(c);
            } else {
                if (adj[c].empty()) rslt--;
                adj[c].insert(b);
            }
        } else {
            if (b < c) {
                adj[b].erase(c);
                if (adj[b].empty()) rslt++;
            } else {
                adj[c].erase(b);
                if (adj[c].empty()) rslt++;
            }
        }
    }
}