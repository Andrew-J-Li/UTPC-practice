#include <bits/stdc++.h>

using namespace std;

int main() {
    int m, s;
    cin >> m >> s;

    if (s == 0 && m != 1) cout << "-1 -1" << endl;
    else if (s > m * 9) cout << "-1 -1" << endl;
    else {
        int tm = m;
        int ts = s;
        string rslt;
        rslt.reserve(m);
        while (tm > 0) {
            if ((tm - 1) * 9 >= ts && (rslt.size() != 0 || m == 1)) {
                rslt += "0";
                tm--;
            } else if ((tm - 1) * 9 >= (ts - 1)) {
                rslt += "1";
                tm--;
                ts--;
            } else {
                int val = ts - ((tm - 1) * 9);
                ts -= val;
                tm--;
                rslt += (val + '0');
            }
        }

        cout << rslt << " ";
        tm = m;
        ts = s;
        rslt = "";
        rslt.reserve(m);
        while (tm > 0) {
            if (ts >= 9) {
                rslt += "9";
                ts -= 9;
                tm--;
            } else if (ts > 0) {
                rslt += (ts + '0');
                ts = 0;
                tm--;
            } else {
                rslt += "0";
                tm--;
            }
        }
        cout << rslt << endl;
    }
}