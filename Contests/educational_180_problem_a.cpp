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
        ll a, x, y;
        cin >> a >> x >> y;
        if (x > a && y > a) cout << "YES" << endl;
        else if (x < a && y < a) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    
    return 0;
}