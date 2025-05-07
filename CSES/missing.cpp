#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll target = (n * (n + 1)) / 2;
    for (ll i = 0; i < n - 1; ++i) {
        ll temp; cin >> temp;
        target -= temp;
    }
    cout << target << endl;
}