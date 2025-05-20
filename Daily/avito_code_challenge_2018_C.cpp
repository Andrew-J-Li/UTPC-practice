#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll root = -1; bool bad = false;
    vector<vector<ll>> adj (n);
    for (ll i = 0; i < n - 1; ++i) {
        ll a, b; cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
        if (adj[a].size() > 2) {
            if (root != -1 && root != a + 1) bad = true;
            else root = a + 1;
        }
        if (adj[b].size() > 2) {
            if (root != -1 && root != b + 1) bad = true;
            else root = b + 1;
        }
    }
    if (bad) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        vector<ll> leaves;
        for (int i = 0; i < adj.size(); ++i) {
            if (adj[i].size() == 1) leaves.push_back(i + 1);
            else if (root == -1 && adj[i].size() == 2) root = i + 1;
        }
        ll rslt = leaves.size();
        if (root == -1) {
            rslt--;
            root = leaves[0];
        }
        cout << rslt << endl;
        for (int i = 0; i < leaves.size(); ++i) {
            if (leaves[i] == root) continue;
            cout << root << " " << leaves[i] << endl; 
        }
    }
}