#include <bits/stdc++.h>

using namespace std;

int main() {
    string a;
    cin >> a;

    bool fa = false;
    bool in = false;
    vector<bool> t (a.size());
    for (int i = a.size() - 1; i >= 0; i--) {
        if (a[i] == 'a' && fa == false) {
            fa = true;
            t[i] = true;
            continue;
        }
        if (a[i] == 'b' && fa == true && in == false) {
            t[i] = true;
            in = true;
        }
        if (a[i] == 'a' && in == true) {
            in = false;
            t[i] = true;
        }
    }

    for (int i = 0; i < t.size(); i++) {
        if (t[i]) cout << 1 << " ";
        else cout << 0 << " ";
    }
    cout << endl;
}