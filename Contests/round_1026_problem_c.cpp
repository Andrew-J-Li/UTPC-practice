#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        vector<int> d(n);
        for (int i = 0; i < n; ++i) cin >> d[i];
        vector<pair<ll, ll>> b(n);
        for (int i = 0; i < n; ++i) cin >> b[i].first >> b[i].second;

        vector<ll> mn(n), mx(n);
        bool imp = false;

        for (int i = 0; i < n; ++i) {
            if (d[i] != -1) {
                if (i != 0) {
                    mn[i] = mn[i-1] + d[i];
                    mx[i] = mx[i-1] + d[i];
                } else {
                    mn[i] = d[i];
                    mx[i] = d[i];
                }
            } else {
                if (i != 0) {
                    mn[i] = mn[i-1];
                    mx[i] = mx[i-1] + 1;
                } else {
                    mn[i] = 0;
                    mx[i] = 1;
                }
            }
            mn[i] = max(mn[i], b[i].first);
            mx[i] = min(mx[i], b[i].second);
            if (mn[i] > mx[i]) imp = true;
        }

        if (imp) {
            cout << -1 << endl;
            continue;
        }

        vector<ll> h(n);
        h[n-1] = mn[n-1];

        for (int i = n-1; i >= 0; --i) {
            if (d[i] != -1) {
                if (i > 0) h[i-1] = h[i] - d[i];
            } else {
                if (i == 0) {
                    if (h[i] == 0) d[i] = 0;
                    else d[i] = 1;
                } else {
                    if (h[i] <= mx[i-1]) {
                        d[i] = 0;
                        h[i-1] = h[i];
                    } else {
                        d[i] = 1;
                        h[i-1] = h[i] - 1;
                    }
                }
            }
        }

        for (int i = 0; i < n; ++i) cout << d[i] << " ";
        cout << endl;
    }
    return 0;
}