#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll T; cin >> T;
    while (T--) {
        ll n; cin >> n;
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        bool good = true;
        int prev = -1;
        for (ll i = 0; i < n; ++i) {
            if (nums[i] == 0) { good = false; break; }
            if (nums[i] != -1 && prev == -1) { prev = nums[i]; continue; }
            if (nums[i] == -1) continue;
            if (nums[i] != prev) { good = false; break; }
        }
        cout << (good ? "YES" : "NO") << endl;
    } 
    return 0;
}