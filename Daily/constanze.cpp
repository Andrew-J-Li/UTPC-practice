#include <bits/stdc++.h>
#define endl "\n"
#define MOD 1000000007
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s; cin >> s;
    ll prev = -1, seq = 0;
    vector<ll> seqs; bool fail = false;
    for (char c : s) {
        if (c == 'm' || c == 'w') fail = true;
        if (c == prev && (c == 'u' || c == 'n')) seq++;
        else {
            if (seq != 1 && (prev == 'u' || prev == 'n')) seqs.push_back(seq);
            prev = c;
            seq = 1;
        }
    }
    if (seq != 1) seqs.push_back(seq);
    if (fail) cout << 0 << endl;
    else {
        ll rslt = 1;
        vector<ll> fib;
        fib.push_back(1); fib.push_back(1);
        for (ll i = 0; i < 100000; ++i) fib.push_back((fib[fib.size() - 1] + fib[fib.size() - 2]) % MOD);
        for (ll i : seqs) rslt = (rslt * fib[i]) % MOD;
        cout << rslt << endl;
    }
}