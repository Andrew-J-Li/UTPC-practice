#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    unordered_set<ll> factors;
    ll temp = n;
    for (ll i = 2; i * i <= n; ++i) {
        if (n % i == 0) factors.insert(i);
        while (n % i == 0) n /= i;
    }
    ll rslt = 1;
    for (ll i : factors) rslt *= i;
    if (n > 1) rslt *= n;
    cout << rslt << endl;
}