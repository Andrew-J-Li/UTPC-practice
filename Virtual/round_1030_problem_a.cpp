#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n, k; cin >> n >> k;
        vector<char> rslt (n);
        for (ll i = 0; i < n; ++i) {
            if (i < k) rslt[i] = '1';
            else rslt[i] = '0';
        }
        for (char c : rslt) cout << c;
        cout << endl;
    }
    return 0;
}