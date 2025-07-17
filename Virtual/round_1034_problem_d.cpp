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
        string s; cin >> s;
        ll ct = 0;
        for (ll i = 0; i < s.size(); ++i) {
            if (s[i] == '1') ct++;
        }
        if (ct <= k) { cout << "ALICE" << endl; continue; }
        if (2 * k > n) { cout << "ALICE" << endl; }
        else cout << "BOB" << endl;
    }
    return 0;
}