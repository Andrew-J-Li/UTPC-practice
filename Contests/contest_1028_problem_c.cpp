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
        vector<ll> idx;
        ll target = -1, mn = LLONG_MAX;
        for (ll i = 0; i < n; ++i) {
            cin >> nums[i];
            mn = min(mn, nums[i]);
            if (target == -1) {
                target = nums[i];
                idx.push_back(i);
                continue;
            }
            ll prev = target;
            target = gcd(target, nums[i]);
            if (prev != target) idx.push_back(i);
        }
        ll rslt = 0;
        if (mn == target) {
            for (ll i = 0; i < n; ++i) if (nums[i] != mn) rslt++;
            cout << rslt << endl;
            continue;
        }
        mn = LLONG_MAX;
        for (ll i = 0; i < n; ++i) {
            ll curr = nums[i];
            ll temp = 0;
            for (ll j = idx.size() - 1; j >= 0; --j) {
                ll prev = curr;
                curr = gcd(curr, nums[idx[j]]);
                if (prev != curr) temp++;
                if (curr == target) break;
            }
            mn = min(mn, temp);
        }
        rslt += mn;
        rslt += n - 1;
        cout << rslt << endl;
    }
    return 0;
}