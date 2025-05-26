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
        int n; cin >> n;
        int rslt = 0, prev = -1;
        for (int i = 0; i < n; ++i) {
            int curr; cin >> curr;
            if (prev == -1) { rslt++; prev = curr; continue; }
            if (curr <= prev + 1) continue;
            rslt++;
            prev = curr;
        }
        cout << rslt << endl;
    }
    return 0;
}