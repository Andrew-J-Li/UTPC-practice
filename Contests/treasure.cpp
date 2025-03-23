#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int b = 0; b < t; b++) {
        int x, y, a;
        cin >> x >> y >> a;
        a++;
        int temp = a % (x + y);
        if (temp == 0) cout << "YES" << endl;
        else if (temp <= x) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}