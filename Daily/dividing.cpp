#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    vector<ll> f;
    ll s = 0;
    for (ll i = n; i >= 1; i -= 2) {
        if ((i / 2) % 2 == 0) f.push_back(i);
        else if (i - 1 >= 1) f.push_back(i - 1);
        s += f[f.size() - 1];
    }
    cout << abs(((n * (n + 1)) / 2) - 2 * s) << endl;
    cout << f.size() << " ";
    for (ll i : f) cout << i << " ";
    cout << endl;
}