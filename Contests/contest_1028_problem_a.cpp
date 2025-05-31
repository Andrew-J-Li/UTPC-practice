#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a <= c) {
            if (b <= a || d <= a) cout << "Gellyfish" << endl;
            else cout << "Flower" << endl;
        } else {
            if (b <= c || d <= c) cout << "Gellyfish" << endl;
            else cout << "Flower" << endl;
        }
    }
    return 0;
}