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
        ll n, m; cin >> n >> m;
        vector<ll> room (m);
        for (ll i = 0; i < m; ++i) cin >> room[i];
        stable_sort(room.begin(), room.end(), [](ll a, ll b) {
            if ((a / 100) != (b / 100)) return (a / 100) < (b / 100);
            else return (a % 100) < (b % 100);
        });
        for (ll i = 0; i < n; ++i) {
            if (i & 1) {
                cout << room[m - 1 - (i / 2)] << " " << room[i / 2] << " ";
                cout << room[m - 1 - (i / 2)] << " " << room[i / 2] << " ";
                cout << room[m - 1 - (i / 2)] << " " << room[i / 2] << " ";
            } else {
                cout << room[(i / 2)] << " " << room[m - 1 - (i / 2)] << " ";
                cout << room[(i / 2)] << " " << room[m - 1 - (i / 2)] << " ";
                cout << room[(i / 2)] << " " << room[m - 1 - (i / 2)] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}