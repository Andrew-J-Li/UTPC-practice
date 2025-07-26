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
        ll n, k; cin >> n >> k;
        k--;
        vector<ll> towers (n);
        for (ll i = 0; i < n; ++i) cin >> towers[i];
        ll cv = towers[k];
        sort (towers.begin(), towers.end());

        ll nx = 0;
        for (ll i = 0; i < n; ++i) {
            if (towers[i] <= cv) nx = i;
            else break;
        }

        ll time = 1;
        while (nx != towers.size() - 1) {
            ll nx_height = towers[nx + 1];
            ll curr_height = towers[nx];

            if (time + (nx_height - curr_height) - 1 > curr_height) break;
            time += (nx_height - curr_height);
            nx++;
        }

        if (nx == towers.size() - 1) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}