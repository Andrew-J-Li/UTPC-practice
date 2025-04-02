#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int prev_a = -1, prev_b = -1, rslt = 0;
    for (int i = 0; i < n; ++i) {
        int a; cin >> a;
        int b; cin >> b;
        if (prev_a < prev_b) {
            if (a >= prev_b) {
                rslt += min(a, b) - prev_b + 1;
            }
        } else if (prev_a == prev_b) {
            rslt += min(a, b) - prev_a;
        } else {
            if (b >= prev_a) {
                rslt += min(a, b) - prev_a + 1;
            }
        }
        prev_a = a;
        prev_b = b;
    }
    cout << rslt << endl;
}