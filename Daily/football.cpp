#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, k; cin >> n >> k;
    ll games = (n * (n - 1)) / 2;
    if (n * k > games) cout << -1 << endl;
    else {
        cout << (n * k) << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j <= i + k; ++j) {
                cout << i + 1 << " " << (j % n) + 1 << endl;
            }
        }
    }
}