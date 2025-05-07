#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    bool one = false;
    ll rslt = 0;
    ll prev = LLONG_MIN;
    for (int i = 0; i < n; ++i) {
        ll temp; cin >> temp;
        if (!one) {
            if (temp == 1) {
                one = true;
                rslt = i;
            }
        } else {
            if (temp < prev) rslt = i;
            prev = temp;
        }
    }
    cout << rslt << endl;
}