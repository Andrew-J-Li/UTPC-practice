#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    for (int a = 0; a < t; ++a) {
        int n, x; cin >> n >> x;
        for (int i = 0; i < x; ++i) cout << i << " ";
        for (int i = n - 1; i >= x; --i) cout << i << " ";
        cout << endl;
    }
}