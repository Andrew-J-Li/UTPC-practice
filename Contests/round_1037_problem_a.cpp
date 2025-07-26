#include <bits/stdc++.h>
#define endl "\n"
#define ll long long

using namespace std;

int main () {

    int t; cin >> t;
    while (t--) {
        int x; cin >> x;
        int rslt = 9;
        while (x != 0) {
            rslt = min (rslt, (x % 10));
            x /= 10;
        }
        cout << rslt << endl;
    }
    return 0;
}