#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> p (n), s (n);
        vector<ll> pgcd (n), sgcd (n);
        for (ll i = 0; i < n; ++i) {
            cin >> p[i];
            if (i == 0) { pgcd[i] = p[i]; continue; }
            pgcd[i] = gcd(pgcd[i - 1], p[i]);
        }
        for (ll i = 0; i < n; ++i) cin >> s[i];
        for (ll i = n - 1; i >= 0; --i) {
            if (i == n - 1) { sgcd[i] = p[i]; continue; }
            sgcd[i] = gcd(sgcd[i + 1], p[i]);
        }

        bool valid = false;
        for (ll i = 0; i < n; ++i) {
            cout << pgcd[i] << " " << sgcd[i] << endl;
            if (pgcd[i] == sgcd[i]) {
                valid = true;
                break;
            }
        }
        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}