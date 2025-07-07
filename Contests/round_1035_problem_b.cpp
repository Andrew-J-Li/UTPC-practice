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
        pair<double, double> p, q;
        cin >> p.first >> p.second >> q.first >> q.second;
        vector<double> ops (n);
        double sum = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> ops[i];
            sum += ops[i];
        }
        double dist = (q.first - p.first) * (q.first - p.first) + (q.second - p.second) * (q.second - p.second);
        dist = sqrt (dist);
        if (n == 1) {
            cout << ((sum == dist) ? "YES" : "NO") << endl;
            continue;
        }

        sum += dist;
        ops.push_back(dist);

        sort (ops.begin(), ops.end(), greater<ll>());
        double mx = ops[0]; sum -= ops[0];
        if (mx <= sum) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}