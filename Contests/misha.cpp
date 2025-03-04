#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    int hs = 0;

    for (int i = 0; i < n; i++) {
        int temp1, temp2; cin >> temp1 >> temp2;
        a[i][0] = temp1;
        hs += a[i][0];
        a[i][1] = temp2;
    }

    queue<int> q;
    cout << hs / 2 << "\n";
    for (int i = 0; i < n; i++) {
        if (a[i][0] == 1) {
            cout << i << " " << a[i][1] << "\n";
            a[i][0]--;
            a[a[i][1]][0]--;
            a[a[i][1]][1] = a[a[i][1]][1] ^ i;
            if (a[a[i][1]][0] == 1) q.push(a[i][1]);
            continue;
        }
    }

    while (!q.empty()) {
        int c = q.front();
        q.pop();
        if (a[c][0] == 0) continue;
        if (a[c][0] == 1) {
            cout << c << " " << a[c][1] << "\n";
            a[a[c][1]][0]--;
            a[a[c][1]][1] = a[a[c][1]][1] ^ c;
            if (a[a[c][1]][0] == 1) q.push(a[c][1]);
            continue;
        }
        q.push(c);
    }
}