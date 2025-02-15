#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n = 0;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        bool good = false;
        for (int i = 0; i < temp.length() - 1; i++) {
            if (temp[i] == temp[i + 1]) {
                good = true;
                cout << 1 << "\n";
                break;
            }
        }

        if (!good) {
            cout << temp.length() << "\n";
        }
    }
}