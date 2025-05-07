#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll prev = -1;
    ll rslt = 0;
    for (ll i = 0; i < n; ++i) {
        ll temp; cin >> temp;
        if (prev == -1) prev = temp;
        rslt += max((ll) 0, prev - temp);
        prev = max(temp, prev);
    }
    cout << rslt << endl;
}