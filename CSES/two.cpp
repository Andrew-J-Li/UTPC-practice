#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n; cin >> n;
    ll sum = ((n + 1) * n) / 2;
    if (sum % 2 == 1) cout << "NO" << endl;
    else {
        ll target = sum / 2;
        vector<ll> a, b;
        for (ll i = n; i >= 1; --i) {
            if (i <= target) {
                a.push_back(i);
                target -= i;
            } else {
                b.push_back(i);
            }
        }
        cout << "YES" << endl;
        cout << a.size() << endl;
        for (ll i : a) cout << i << " ";
        cout << endl;
        cout << b.size() << endl;
        for (ll i : b) cout << i << " ";
        cout << endl;
    }
}