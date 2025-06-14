#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

class DSU {
public:
    vector<ll> rank, parent;
    vector<unordered_set<ll>> connect;

    DSU (ll n) {
        parent.resize(n);
        rank.resize(n, 0);
        connect.resize(n);
        for (ll i = 0; i < n; ++i) {
            parent[i] = i;
            connect[i].insert(i);
        }
    }

    ll find (ll i) {
        ll root = parent[i];
        if (parent[root] != root) return parent[i] = find(root);
        return root;
    }

    void unite (ll x, ll y) {
        ll xr = find(x);
        ll yr = find(y);
        if (xr == yr) return;
        if (rank[xr] < rank[yr]) {
            parent[xr] = yr;
            connect[yr].insert(connect[xr].begin(), connect[xr].end());
            connect[xr].clear();
        } else {
            parent[yr] = xr;
            connect[xr].insert(connect[yr].begin(), connect[yr].end());
            connect[yr].clear();
            if (rank[yr] == rank[xr]) rank[xr]++;
        }
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, m_1, m_2; cin >> n >> m_1 >> m_2;
        vector<pair<ll, ll>> q (m_1);
        for (ll i = 0; i < m_1; ++i) {
            ll a, b; cin >> a >> b;
            a--; b--;
            q[i].first = a; q[i].second = b;
        }
        DSU check (n);
        for (ll i = 0; i < m_2; ++i) {
            ll a, b; cin >> a >> b;
            a--; b--;
            check.unite (a, b);
        }
        DSU test (n);
        ll rslt = 0;
        for (ll i = 0; i < q.size(); ++i) {
            ll ta = test.find (q[i].first);
            ll tb = test.find (q[i].second);
            ll fa = check.find (q[i].first);
            ll fb = check.find (q[i].second);
            if (fa == fb) {
                if (ta == tb) continue;
                test.unite (q[i].first, q[i].second);
            } else {
                rslt++;
            }
        }
        for (ll i = 0; i < check.connect.size(); ++i) {
            if (check.connect[i].empty()) continue;
            for (ll it : check.connect[i]) {
                ll a = test.find (i);
                ll b = test.find (it);
                if (a != b) {
                    test.unite (i, it);
                    rslt++;
                }
            }
        }
        cout << rslt << endl;
    }
    return 0;
}