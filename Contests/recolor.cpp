#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long t;
    cin >> t;
    for (long long a = 0; a < t; a++) {
        long long n, k;
        cin >> n >> k;
        vector<long long> g(n);
        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            g[i] = temp;
        }
        long long rslt = 0;
        if (k == 1) {
            rslt = g[0] + g[n - 1];
            for (long long i = 1; i < n - 1; i++) {
                rslt = max(rslt, max(g[i] + g[0], g[i] + g[n - 1]));
            }
        } else {
            sort(g.begin(), g.end());
            long long up = g.size() - (k + 1);
            for (long long i = g.size() - 1; i >= up; i--) {
                rslt += g[i];
            }
        }
        cout << rslt << endl;
    }
}