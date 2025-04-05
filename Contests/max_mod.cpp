#include <bits/stdc++.h>

using namespace std;

int main() {
    int t; cin >> t;
    for (int a = 0; a < t; ++a) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << "-1" << endl;
        } else {
            cout << n << " ";
            for (int i = 1; i <= n - 1; ++i) {
                cout << i << " ";
            }
        }
    }
}