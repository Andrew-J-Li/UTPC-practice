#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long z = 0; z < t; z++) {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long q = 0; q < n; q++) {
            cin >> a[q];
        }
        sort(a.begin(), a.end());
        long long lo = 0, hi = 0, prev_hi = -1, ph_idx = -1, rslt = 0;
        while (hi < a.size()) {
            if (a[hi] > a[lo] + 2) {
                hi--;
                if (hi - lo + 1 >= 3) {
                    if (a[hi] != prev_hi) {
                        long long count = hi - lo + 1;
                        rslt += (count * (count - 1) * (count - 2)) / 6;
                         long long pcount = ph_idx - lo + 1;
                        if (pcount >= 3) rslt -= (pcount * (pcount - 1) * (pcount - 2)) / 6;
                        prev_hi = a[hi];
                        ph_idx = hi;
                    }
                }
                 long long prev_lo = a[lo];
                while (a[lo] == prev_lo) lo++;
                if (hi < lo) hi = lo;
            } else {
                hi++;
            }
        }
        hi--;
        if (a[hi] <= a[lo] + 2 && hi - lo + 1 >= 3) {
            if (a[hi] != prev_hi) {
                 long long pcount = ph_idx - lo + 1;
                if (pcount >= 3) rslt -= (pcount * (pcount - 1) * (pcount - 2)) / 6;
                ph_idx = hi;
                prev_hi = a[hi];
                 long long count = hi - lo + 1;
                rslt += (count * (count - 1) * (count - 2)) / 6;
            }
        }
        cout << rslt << endl;
    }
    return 0;
}