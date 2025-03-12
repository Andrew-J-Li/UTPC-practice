#include <bits/stdc++.h>

using namespace std;


int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    int rslt = 0;
    int mc = min(x, y);
    int l = (x < y) ? a : b;
    if (c < mc * l) {
        cout << c / mc << endl;
    } else {
        rslt += l;
        c -= mc * l;
        mc = max(x, y);
        l = (x < y) ? b : a;
        if (c < mc * l) {
            rslt += c / mc;
            cout << rslt << endl;
        } else {
            rslt += l;
            cout << rslt << endl;
        }
    }
}