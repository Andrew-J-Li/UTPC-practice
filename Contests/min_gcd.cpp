#include <bits/stdc++.h>

#define ll long long

using namespace std;

ll gcd (ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ll t; cin >> t;
    for (ll a = 0; a < t; ++a) {
        ll n; cin >> n;
        vector<ll> nums (n);
        ll w = LLONG_MAX;
        ll cnt = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];
            if (nums[i] < w) cnt = 1;
            else if (nums[i] == w) cnt++;
            w = min(w, nums[i]);
        }

        if (cnt >= 2) {
            cout << "yes" << endl;
            continue;
        }

        ll cd = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] % w == 0 && nums[i] > w) {
                cd = gcd (cd, nums[i] / w);
                if (cd == 1) break;
            }
        }
        if (cd == 1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}