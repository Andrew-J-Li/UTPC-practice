#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    for (ll a = 0; a < t; ++a) {
        ll n, k; cin >> n >> k;
        vector<ll> top (n);
        ll min_top = LLONG_MAX;
        ll max_top = LLONG_MIN;
        vector<ll> bot (n);
        for (ll i = 0; i < n; ++i) {
            cin >> top[i];
            min_top = min(min_top, top[i]);
            max_top = max(max_top, top[i]);
        }
        bool all = true;
        bool good = true;
        ll prev_sum = -1;
        for (ll i = 0; i < n; ++i) {
            cin >> bot[i];
            if (bot[i] != -1) {
                all = false;
                if (prev_sum == -1) prev_sum = bot[i] + top[i];
                else if (bot[i] + top[i] != prev_sum) good = false;
            }
        }
        if (!all) {
            if (!good) cout << 0 << endl;
            else {
                bool good_again = true;
                for (ll i = 0; i < n; ++i) {
                    if (prev_sum - top[i] > k || prev_sum - top[i] < 0) {
                        cout << 0 << endl;
                        good_again = false;
                        break;
                    }
                    if (bot[i] != -1 && bot[i] != prev_sum - top[i]) {
                        cout << 0 << endl;
                        good_again = false;
                        break;
                    }
                }
                if (good_again) cout << 1 << endl;
            }
        } else {
            ll rslt = (min_top + k - max_top) + 1;
            cout << rslt << endl;
        }
    }
}