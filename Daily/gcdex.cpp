#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

const ll MAX_N = 1e6;
ll ans[MAX_N + 1];
ll phi[MAX_N + 1];

void phi_1_to_n () {
    ll n = MAX_N;
    for (ll i = 1; i <= n; ++i) phi[i] = i;
    for (ll i = 2; i <= n; ++i) {
        if (phi[i] == i) {
            for (ll j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    phi_1_to_n();
    for (ll i = 2; i <= MAX_N; ++i) { phi[i] += phi[i - 1]; }

    ll n; cin >> n;
    while (n) {
        ll rslt = 0;
        for (ll d = 1; d <= n; ++d) rslt += d * (phi[n / d] - 1);
        cout << rslt << endl;
        cin >> n;
    }
    return 0;
}