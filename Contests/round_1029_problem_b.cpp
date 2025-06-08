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
        cout << 2 << " ";
        for (ll i = n; i > 2; --i) cout << i << " ";
        cout << 1 << " " << endl;
    }
    return 0;
}