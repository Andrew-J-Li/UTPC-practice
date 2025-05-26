#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int t = stoi(s);
        double a = sqrt((double) t);
        if (a != (int) a) {
            cout << -1 << endl;
            continue;
        }
        cout << 0 << " " << a << endl;
    }    
    return 0;
}