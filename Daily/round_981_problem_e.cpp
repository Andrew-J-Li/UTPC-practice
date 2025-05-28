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
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        ll rslt = 0;
        vector<bool> visited (n);
        for (ll i = 0; i < n; ++i) {
            if (visited[i]) continue;
            int curr = i;
            int len = 0;
            while (!visited[curr]) {
                len++;
                visited[curr] = true;
                curr = nums[curr] - 1;
            }
            rslt += (len - 1) / 2;
        }
        cout << rslt << endl;
    }
    return 0;
}