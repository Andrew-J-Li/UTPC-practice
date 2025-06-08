#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll gcd (ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        bool rslt = true;
        ll prev_x = -1, prev_y = -1;
        for (ll i = 1; i <= 1; ++i) {
            ll temp = nums[i - 1] - (n - i + 1) * nums[n - i];
            if (temp % (i * i - (n - i + 1) * (n - i + 1)) != 0) { rslt = false; break; }
            temp /= (i * i - (n - i + 1) * (n - i + 1));
            ll temp_y = nums[i - 1] - (i * temp);
            if (temp_y % (n - i + 1) != 0) { rslt = false; break; }
            temp_y /= (n - i + 1);
            if (temp < 0 || temp_y < 0) { rslt = false; break; }
            if (prev_x == -1 && prev_y == -1) { prev_x = temp; prev_y = temp_y; }
            else if (prev_x != temp || prev_y != temp_y) { rslt = false; break; }
        }
        for (ll i = 1; i <= n; ++i) {
            if (prev_x * i + (n - i + 1) * prev_y != nums[i - 1]) { rslt = false; break; }
        }
        if (rslt) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}