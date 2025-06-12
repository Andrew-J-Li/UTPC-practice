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
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        vector<pair<ll, char>> cell;
        for (ll i = 0; i < n; ++i) {
            ll curr; cin >> curr;
            if (i == 0) { cell.push_back(make_pair(curr, s[i])); continue; }
            if (s[i] == cell[cell.size() - 1].second) cell[cell.size() - 1].first = max(cell[cell.size() - 1].first, curr);
            else cell.push_back(make_pair(curr, s[i]));
        }
        ll lo = 0, hi = 1000000000, rslt = LLONG_MAX;
        while (lo <= hi) {
            ll tr = 0, ct = 0;
            ll mid = (lo + hi) / 2;
            vector<bool> v (cell.size());
            for (ll i = 0; i < cell.size(); ++i) {
                if (cell[i].second == 'B') {
                    if (cell[i].first > mid) {
                        if (i != 0 && v[i - 1]) v[i] = true;
                        else { ct++; v[i] = true; }
                    } else if (i != 0 && v[i - 1]) {
                        v[i] = true;
                    } else {
                        tr = max(tr, cell[i].first);
                    }
                } else {
                    if (cell[i].first <= mid && i != 0 && v[i - 1]) {
                        v[i] = true;
                        tr = max(tr, cell[i].first);
                    }
                }
            }
            if (ct > k) {
                lo = mid + 1;
            } else {
                rslt = min(rslt, tr);
                hi = mid - 1;
            }
        }
        cout << rslt << endl;
    }
    return 0;
}