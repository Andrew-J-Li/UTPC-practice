#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

ll gcd (ll a, ll b) {
    while (b > 0) {
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
        ll target = -1;
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];
            if (target == -1) target = nums[i];
            else target = gcd(target, nums[i]);
        }
        
    }
    return 0;
}