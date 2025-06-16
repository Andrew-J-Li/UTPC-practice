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
        ll n, k; cin >> n >> k;
        ll mul = n + 1, sum = 0, curr = 1;
        while (n >= k) {
            if (n & 1) sum += curr;
            n >>= 1;
            curr <<= 1;
        }
        cout << mul * sum / 2 << endl;
    }
    return 0;
}