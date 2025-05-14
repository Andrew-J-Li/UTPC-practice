#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll rslt = 0, prev = 0, po = 0;
    for (ll i = 0; i < n; ++i) {
        ll curr; cin >> curr;
        if (curr < prev) {
            rslt += max((ll) 0, prev - curr - po);
            po = max(po, prev - curr);
            prev = max(prev, curr + po);
        } else if (curr >= prev) prev = max(prev, curr + po);
    }
    cout << rslt << endl;
}