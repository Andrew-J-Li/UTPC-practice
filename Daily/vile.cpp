#include <bits/stdc++.h>

using namespace std;

int main() {
    int p, y; cin >> p >> y;
    bool very_good = false;
    for (int i = y; i >= max (p + 1, y - 400); --i) {
        bool good = true;
        for (int j = 2; j * j <= i; ++j) {
            if (i % j == 0 && j <= p) {
                good = false;
                break;
            }
        }
        if (good) {
            very_good = true;
            cout << i << endl;
            break;
        }
    }
    if (!very_good) cout << -1 << endl;
}