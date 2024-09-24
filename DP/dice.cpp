#include <bits/stdc++.h>
#define ll long long
#define vt vector
#define endl '\n'
#define sz(x) (int)x.size()
#define pb push_back
#define pf push_front
#define uset unordered_set
#define umap unordered_map
struct pii {
    int x, y;
};

using namespace std;

int main() {
    ll N;
    cin >> N;
    vector<ll> p(N + 1, 0);
    p[0] = 1;
    for (ll i = 0; i <= N; i++) {
        for (ll j = 1; i >= j && j <= 6; j++) {
            p[i] = (p[i] + p[i - j]) % (1000000007);
        }
    }
    cout << p[N] << '\n';
}