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
        bool all_one = true; int prev = -1;
        bool bad = false;
        for (int i = 0; i < n; ++i) {
            int temp; cin >> temp;
            if (temp != 1) all_one = false;
            if (prev == -1) {
                prev = temp;
                continue;
            }
            if (prev == 0 && temp == 0) bad = true;
            prev = temp;
        }
        if (bad || all_one) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}