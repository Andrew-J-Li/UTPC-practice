#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    unsigned ll n; cin >> n;
    unsigned ll rslt = 0;
    for (unsigned ll i = 1; i * i <= n; ++i) {
        unsigned ll curr = ((((n / i) - i + 1ULL) % MOD) * i) % MOD;
        rslt = (rslt + curr) % MOD;

        if (i + 1 > n / i) continue;
        unsigned ll t1 = (n / i - i), t2 = (i + 1 + (n / i));
        if (t1 & 1) curr = (((t2 / 2ULL) % MOD) * (t1 % MOD)) % MOD;
        else curr = (((t1 / 2ULL) % MOD) * (t2 % MOD)) % MOD;
        rslt = (rslt + curr) % MOD;
    }

    cout << rslt << endl;
    return 0;
}