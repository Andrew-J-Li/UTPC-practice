#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll rslt = 0;
    ll x; cin >> x;
    unordered_set<ll> nums;
    ll goof = x;

    while (goof > 0) {
        ll temp = goof % 10;
        nums.insert(temp);
        goof /= 10;
    }

    for (ll i = 1; i * i <= x; ++i) {
        if (x % i == 0) {
            ll temp = i;
            bool good = false;
            while (temp > 0) {
                if (nums.count(temp % 10) > 0) {
                    good = true;
                    break;
                }
                temp /= 10;
            }
            if (good) rslt++;
            temp = x / i;
            good = false;
            while (temp > 0 && (x / i) != i) {
                if (nums.count(temp % 10) > 0) {
                    good = true;
                    break;
                }
                temp /= 10;
            }
            if (good) rslt++;
        }
    }
    cout << rslt << endl;
}