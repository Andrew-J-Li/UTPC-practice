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
        ll n, m, p, q;
        cin >> n >> m >> p >> q;
        if (n % p != 0) { cout << "YES" << endl; continue; }
        ll val = (n / p) * q;
        if (m == val) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}