#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, k; cin >> n >> m >> k;
    pair<ll, ll> loc = {1, 1};
    if (k < n) {
        loc.first += k;
    } else if (k < n + m - 1) {
        loc.first = n;
        loc.second += (k - (n - 1));
    } else {
        loc = {n, m};
        k -= (n + m - 2);
        loc.first -= (k / (m - 1) + ((k % (m - 1) != 0) ? 1 : 0));
        k -= (k / (m - 1) + ((k % (m - 1) != 0) ? 1 : 0));
        if (m != 2) {
            loc.second = ((k / (m - 2)) % 2 == 0 ? m : 2);
            loc.second += (loc.second == 2) ? k % (m - 2) : -(k % (m - 2));
        }
    }
    cout << loc.first << " " << loc.second << endl;
}