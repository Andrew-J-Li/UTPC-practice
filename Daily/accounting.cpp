#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    if (a == 0) {
        if (b == 0) cout << "0" << endl;
        else cout << "No solution" << endl;
    } else if (b % a != 0) {
        cout << "No solution" << endl;
    } else {
        b /= a;
        if (b < 0) {
            if (n % 2 == 0) {
                cout << "No solution" << endl;
            } else {
                int i = 0;
                while (true) {
                    if (pow(i, n) == b) {
                        cout << i << endl;
                        break;
                    }
                    if (pow(i, n) < b) {
                        cout << "No solution" << endl;
                        break;
                    }
                    --i;
                }
            }
        } else {
            int i = 0;
            while (true) {
                if (pow(i, n) == b) {
                    cout << i << endl;
                    break;
                }
                if (pow(i, n) > b) {
                    cout << "No solution" << endl;
                    break;
                }
                ++i;
            }
        }
    }
}