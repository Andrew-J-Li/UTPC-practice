#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    // cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        set<pair<ll, ll>> rslt;
        unordered_set<ll> v;
        v.insert(1);
        for (ll i = 2; i <= n; ++i) {
            queue<pair<ll, ll>> q;
            if (v.count(i)) continue;
            q.push({1, i});
            while (!q.empty()) {
                pair<ll, ll> curr = q.front();
                q.pop();
                if (v.count(curr.first) && v.count(curr.second)) continue;
                cout << "? " << curr.first << " " << curr.second << endl;
                cout.flush();
                ll ans; cin >> ans;
                if (ans == -1) return 0;
                if (ans == curr.first) {
                    rslt.insert({curr.first, curr.second});
                    v.insert(curr.second);
                } else {
                    q.push({ans, curr.second});
                    q.push({curr.first, ans});
                }
            }
        }
        cout << "! ";
        for (pair<ll, ll> it : rslt) cout << it.first << " " << it.second << " ";
        cout << endl;
        cout.flush();
    }
    return 0;
}