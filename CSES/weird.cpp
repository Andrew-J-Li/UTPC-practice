#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    while (n != 1) {
        cout << n << " ";
        if (n % 2 == 1) n = 3 * n + 1;
        else n /= 2;
    }
    cout << n << endl;
}