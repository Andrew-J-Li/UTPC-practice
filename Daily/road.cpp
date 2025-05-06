#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m; cin >> n >> m;
    vector<bool> cities (n);
    for (int i = 0; i < m; ++i) {
        int a, b; cin >> a >> b;
        a--; b--;
        cities[a] = true; cities[b] = true;
    }

    int target = 0;
    for (int i = 0; i < n; ++i) {
        if (!cities[i]) {
            target = i;
            break;
        }
    }

    cout << n - 1 << endl;
    for (int i = 0; i < n; ++i) {
        if (i == target) continue;
        cout << i + 1 << " " << target + 1 << endl;
    }
}