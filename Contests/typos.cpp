#include <bits/stdc++.h>

using namespace std;


int main() {
    string s;
    cin >> s;
    vector<char> rslt;

    int c = 0;
    int seq = 0;
    char prev = '0';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != prev) {
            prev = s[i];
            rslt.push_back(s[i]);
            if (c >= 2) seq++;
            else seq = 0;
            c = 1;
            continue;
        }
        c++;
        if (c == 2) {
            if (seq % 2 == 0) rslt.push_back(s[i]);
        }
    }

    for (int i = 0; i < rslt.size(); i++) {
        cout << rslt[i];
    }
    cout << endl;
}