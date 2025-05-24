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
        int count = 0; bool yes = false;
        for (int i = 0; i < s.size(); ++i) {
            if (count == 0 && i != 0) yes = true;
            if (s[i] == '(') count++;
            else count--;
        }
        cout << ((yes) ? "YES" : "NO") << endl;
    }
    return 0;
}