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
    int n, x;
    cin >> n >> x;
    vector<int> c(n, 0);
    for (int i = 0 ; i < n; i++) {
        cin >> c[i];
    }

    vector<int> p(x + 1, 0);
    p[0] = 1;
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (c[j] > i) {
                continue;
            }
            p[i] = (p[i] + p[i - c[j]]) % (1000000007);
        }
    }
    cout << p[x] << '\n';
}