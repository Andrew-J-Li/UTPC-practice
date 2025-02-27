#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n, k;
    cin >> n;
    cin >> k;
    int top = 0;
    int tim = 0;

    while (true) {
        int temp;
        if (n > 0) {
            cin >> temp;
            top += temp;
            n--;
        }

        tim++;
        top = max(0, top - k);
        if (n <= 0 && top <= 0) break;
    }

    cout << tim << endl;
}
