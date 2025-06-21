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
        ll l1, b1, l2, b2, l3, b3;
        cin >> l1 >> b1 >> l2 >> b2 >> l3 >> b3;
        ll a = (l1 * b1) + (l2 * b2) + (l3 * b3);
        if ((ll) sqrt(a) * (ll) sqrt(a) != a) { cout << "NO" << endl; continue; }
        ll side = sqrt(a);
        if (l1 == l2 && l2 == l3 && l3 == side) { cout << "YES" << endl; continue; }
        if (l1 == side && l2 + l3 == side) { cout << "YES" << endl; continue; }
        if (l2 == side && l1 + l3 == side) { cout << "YES" << endl; continue; }
        if (l3 == side && l1 + l2 == side) { cout << "YES" << endl; continue; }
        if (b1 == b2 && b2 == b3 && b3 == side) { cout << "YES" << endl; continue; }
        if (b1 == side && b2 + b3 == side) { cout << "YES" << endl; continue; }
        if (b2 == side && b1 + b3 == side) { cout << "YES" << endl; continue; }
        if (b3 == side && b1 + b2 == side) { cout << "YES" << endl; continue; }       
        cout << "NO" << endl;
    }
    return 0;
}