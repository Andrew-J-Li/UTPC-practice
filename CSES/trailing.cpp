#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll curr = 5;
    ll rslt = 0;
    while (curr <= n) {
        rslt += (n / curr);
        curr *= 5;
    }
    cout << rslt << endl;
}