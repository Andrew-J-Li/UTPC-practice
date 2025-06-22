#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, m; cin >> n >> m;
        if (m < n || m > (n * (n + 1) / 2)) { cout << -1 << endl; continue; }
        if (m <= 2 * n - 1) {
            ll root = m - n + 1;
            cout << root << endl;
            ll prev = root;
            for (ll i = 1; i <= n; ++i) {
                if (i == root) continue;
                cout << prev << " " << i << endl;
                prev = i;
            }
            continue;
        }
        unordered_set<ll> nodes;
        ll sum = (n * (n + 1)) / 2;
        ll curr = n - 1;
        while (sum != m) {
            if (sum - curr + 1 >= m) {
                sum -= curr - 1;
                nodes.insert(curr);
            }
            curr--; 
        }
        cout << n << endl;
        for (ll i = 1; i < n; ++i) {
            if (nodes.count(i)) continue;
            cout << n << " " << i << endl;
        }
        for (ll it : nodes) cout << 1 << " " << it << endl;
    }
    return 0;
}