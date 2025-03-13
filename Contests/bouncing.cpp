#include <bits/stdc++.h>


using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, p, k;
        cin >> n >> p >> k;
        p--;

        string s;
        cin >> s;

        long long x, y;
        cin >> x >> y;

        vector<int> ps (n);
        for (int j = n - 1; j >= 0; j--) {
            if (j + k >= n) ps[j] = (s[j] == '0') ? 1 : 0;
            else ps[j] = ps[j + k] + ((s[j] == '0') ? 1 : 0);
        }

        long long mr = LONG_LONG_MAX;

        for (int i = p; i < n; i++) {
            long long temp = y * (i - p);
            temp += x * ps[i];
            mr = min(mr, temp);
        }

        cout << mr << endl;
    }
}