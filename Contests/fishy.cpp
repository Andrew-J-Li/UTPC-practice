#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    cout << "o-----------------------o" << endl;
    cout << "|";
    if (n <= 7) {
        for (int i = 0; i < n; ++i) cout << "<><";
        for (int i = 0; i < 23 - 3 * n; ++i) cout << " ";
        cout << "|" << endl;
        for (int i = 0; i < 12; ++i) cout << "|                       |" << endl;
        cout << "o-----------------------o" << endl;
    } else {
        n -= 7;
        for (int i = 0; i < 7; ++i) cout << "<><";
        for (int i = 0; i < 2; ++i) cout << " ";
        cout << "|" << endl;
        cout << "|";
        for (int i = 0; i < n; ++i) cout << "<><";
        for (int i = 0; i < 23 - 3 * n; ++i) cout << " ";
        cout << "|" << endl;
        for (int i = 0; i < 11; ++i) cout << "|                       |" << endl;
        cout << "o-----------------------o" << endl;
    }
}