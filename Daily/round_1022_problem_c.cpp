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
        ll n; cin >> n;
        vector<pair<ll, ll>> buttons (n);
        vector<ll> origin (n);
        vector<bool> joined (n);
        ll rslt = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> buttons[i].first;
            buttons[i].second = i;
            origin[i] = buttons[i].first;
        }
        sort(buttons.begin(), buttons.end(), greater<pair<ll, ll>>());
        for (ll i = 0; i < buttons.size(); ++i) {
            if (!joined[buttons[i].second]) {
                rslt++;
                joined[buttons[i].second] = true;
            }
            ll prev = -1;
            for (ll j = buttons[i].second - 1; j >= 0; --j) {
                if (prev == -1) prev = origin[j];
                if (origin[j] != prev || joined[j]) break;
                joined[j] = true;
            }
            prev = -1;
            for (ll j = buttons[i].second + 1; j < n; ++j) {
                if (prev == -1) prev = origin[j];
                if (origin[j] != prev || joined[j]) break;
                joined[j] = true;
            }
        }
        cout << rslt << endl;
    }
    return 0;
}