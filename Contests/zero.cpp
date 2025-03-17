#include <bits/stdc++.h>


using namespace std;

int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int n, k;
        cin >> n >> k;
        int rslt = 0;
        while (n > 0) {
            if (n % 2 == 1) {
                n -= k;
                rslt++;
            } else {
                rslt += ceil((double) n / (k - 1));
                n = 0;
            }
        }
        cout << rslt << endl;
    }
}