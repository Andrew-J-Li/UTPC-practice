#include <bits/stdc++.h>

#define MOD_VAL 998244353

using namespace std;

long long bin_pow (long long a, long long b);

int main() {
    unsigned long long n;
    cin >> n;

    unsigned long long rslt = 0;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;

        for (int j = 0; j < temp.size(); j++) {
            rslt += (unsigned long long) ((temp[(int) temp.size() - j - 1] - '0') * bin_pow (10, 2 * j) * (n)) % MOD_VAL;
            rslt += (unsigned long long) ((temp[(int) temp.size() - j - 1] - '0') * bin_pow(10, 2 * j + 1) * (n)) % MOD_VAL;
            rslt %= MOD_VAL;
        }
    }
    cout << rslt << endl;
}

long long bin_pow (long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * a) % MOD_VAL;
            res %= MOD_VAL;
        }
        a = (a * a) % MOD_VAL;
        b >>= 1;
    }
    return res;
}