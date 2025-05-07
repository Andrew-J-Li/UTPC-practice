#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    char prev = 'Z';
    int rslt = 0;
    int curr = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (prev == 'Z') {
            prev = s[i];
            curr++;
            rslt = max(rslt, curr);
            continue;
        }
        if (s[i] != prev) {
            curr = 1;
            rslt = max(rslt, curr);
            prev = s[i];
        } else {
            curr++;
            rslt = max(rslt, curr);
        }
    }
    cout << rslt << endl;
}