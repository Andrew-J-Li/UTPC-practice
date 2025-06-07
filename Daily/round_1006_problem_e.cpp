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
        ll k; cin >> k;
        if (k == 0) { cout << 0 << endl; continue; }
        ll cf = 0, cs = 0, nx = 0;
        vector<pair<ll, ll>> rslt;
        while (k > 0) {
            if (nx == 0) {
                rslt.push_back({cf, cs});
                rslt.push_back({cf, cs + 1});
                cs += 2;
                nx = 2;
                k--;
                continue;
            }
            if (k - nx < 0) {
                nx = 0;
                cf++;
                continue;
            }
            rslt.push_back({cf, cs});
            k -= nx;
            nx++;
            cs++;
        }
        cout << rslt.size() << endl;
        for (pair<ll, ll> it : rslt) cout << it.first << " " << it.second << endl;
    }
    return 0;
}