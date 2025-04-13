#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll w, h, rslt = 0; cin >> w >> h;
    for (ll i = 2; i <= h; i += 2) {
        for (ll j = 2; j <= w; j += 2) {
            rslt += (h - (i - 1)) * (w - (j - 1));
        }
    }
    cout << rslt << endl;
}