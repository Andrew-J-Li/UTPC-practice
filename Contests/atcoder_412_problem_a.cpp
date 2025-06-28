#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll rslt = 0;
    for (ll i = 0; i < n; ++i) {
        ll a, b; cin >> a >> b;
        if (b > a) rslt++;
    }
    cout << rslt << endl;
    return 0;
}