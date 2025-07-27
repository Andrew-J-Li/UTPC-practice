#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

ll gcd (ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    ll n; cin >> n;
    vector<ll> rslt;
    rslt.push_back(1);
    for (ll i = 2; i < n; ++i) {
        if (gcd(i, n) != 1) continue;
        rslt.push_back(i);
    }

    ll curr = 1;
    for (ll i : rslt) {
        curr = (curr * i) % n;
    }
    if (curr != 1) rslt.pop_back();

    cout << rslt.size() << endl;
    for (ll i : rslt) cout << i << " ";
    cout << endl;

    return 0;
}