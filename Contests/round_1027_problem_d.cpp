#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

bool comp(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<pair<ll, ll>> x (n);
        vector<pair<ll, ll>> y (n);
        for (ll i = 0; i < n; ++i) {
            cin >> x[i].first >> x[i].second;
            y[i].first = x[i].first; y[i].second = x[i].second;
        }
        if (n == 1) { cout << 1 << endl; continue; }
        sort(x.begin(), x.end());
        sort(y.begin(), y.end(), comp);
        ll rslt = (x[n - 1].first - x[0].first + 1) * (y[n - 1].second - y[0].second + 1);
        if (rslt == n) {cout << n << endl; continue; }
        ll x_1, x_n, y_1, y_n;
        if (x[0].first == y[0].first && x[0].second == y[0].second) {
            x_1 = (x[n - 1].first - x[1].first + 1) * (y[n - 1].second - y[1].second + 1);
            if (x_1 == n - 1) x_1 += min(x[n - 1].first - x[1].first + 1, y[n - 1].second - y[1].second + 1);
        } else if (x[0].first == y[n - 1].first && x[0].second == y[n - 1].second) {
            x_1 = (x[n - 1].first - x[1].first + 1) * (y[n - 2].second - y[0].second + 1);
            if (x_1 == n - 1) x_1 += min(x[n - 1].first - x[1].first + 1, y[n - 2].second - y[0].second + 1);
        } else {
            x_1 = (x[n - 1].first - x[1].first + 1) * (y[n - 1].second - y[0].second + 1);
            if (x_1 == n - 1) x_1 += min(x[n - 1].first - x[1].first + 1, y[n - 1].second - y[0].second + 1);
        }
        rslt = min(rslt, x_1);

        if (x[n - 1].first == y[0].first && x[n - 1].second == y[0].second) {
            x_n = (x[n - 2].first - x[0].first + 1) * (y[n - 1].second - y[1].second + 1);
            if (x_n == n - 1) x_n += min(x[n - 2].first - x[0].first + 1, y[n - 1].second - y[1].second + 1);
        } else if (x[n - 1].first == y[n - 1].first && x[n - 1].second == y[n - 1].second) {
            x_n = (x[n - 2].first - x[0].first + 1) * (y[n - 2].second - y[0].second + 1);
            if (x_n == n - 1) x_n += min(x[n - 2].first - x[0].first + 1, y[n - 2].second - y[0].second + 1);
        } else {
            x_n = (x[n - 2].first - x[0].first + 1) * (y[n - 1].second - y[0].second + 1);
            if (x_n == n - 1) x_n += min(x[n - 2].first - x[0].first + 1, y[n - 1].second - y[0].second + 1);
        }
        rslt = min(rslt, x_n);

        if (y[0].first == x[0].first && y[0].second == x[0].second) {
            y_1 = (x[n - 1].first - x[1].first + 1) * (y[n - 1].second - y[1].second + 1);
            if (y_1 == n - 1) y_1 += min(x[n - 1].first - x[1].first + 1, y[n - 1].second - y[1].second + 1);
        } else if (y[0].first == x[n - 1].first && y[0].second == x[n - 1].second) {
            y_1 = (x[n - 2].first - x[0].first + 1) * (y[n - 1].second - y[1].second + 1);
            if (y_1 == n - 1) y_1 += min(x[n - 2].first - x[0].first + 1, y[n - 1].second - y[1].second + 1);
        } else {
            y_1 = (x[n - 1].first - x[0].first + 1) * (y[n - 1].second - y[1].second + 1);
            if (y_1 == n - 1) y_1 += min(x[n - 1].first - x[0].first + 1, y[n - 1].second - y[1].second + 1);
        }
        rslt = min(rslt, y_1);

        if (y[n - 1].first == x[0].first && y[n - 1].second == x[0].second) {
            y_n = (x[n - 1].first - x[1].first + 1) * (y[n - 2].second - y[0].second + 1);
            if (y_n == n - 1) y_n += min(x[n - 1].first - x[1].first + 1, y[n - 2].second - y[0].second + 1);
        }
        else if (y[n - 1].first == x[n - 1].first && y[n - 1].second == x[n - 1].second) {
            y_n = (x[n - 2].first - x[0].first + 1) * (y[n - 2].second - y[0].second + 1);
            if (y_n == n - 1) y_n += min(x[n - 2].first - x[0].first + 1, y[n - 2].second - y[0].second + 1);
        } else {
            y_n = (x[n - 1].first - x[0].first + 1) * (y[n - 2].second - y[0].second + 1);
            if (y_n == n - 1) y_n += min(x[n - 1].first - x[0].first + 1, y[n - 2].second - y[0].second + 1);
        }
        rslt = min(rslt, y_n);

        cout << rslt << endl;
    }
    return 0;
}