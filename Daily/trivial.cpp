#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll m; cin >> m;
    ll curr = 5, i = 1;
    while (i < m) {
        ll temp = curr + 5, inc = 0;
        while (temp % 5 == 0) {
            inc++;
            temp /= 5;
        }
        i += inc;
        curr += 5;
    }
    if (i > m) cout << 0 << endl;
    else {
        cout << 5 << endl;
        for (int j = curr; j < curr + 5; ++j) {
            cout << j << " ";
        }
        cout << endl;
    }
}