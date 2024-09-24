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
    int N;
    cin >> N;
    vector<int> h(N,0);
    for (int i = 0; i < N; i++) {
        cin >> h[i];
    }

    vector<int> p(N, 1e9);
    p[0] = 0;
    for (int i = 0; i < N - 1; i++) {
        if (i < N - 2) {
            p[i + 2] = min(p[i] + abs(h[i] - h[i + 2]), p[i+2]);
        }

        p[i + 1] = min(p[i] + abs(h[i] - h[i + 1]), p[i + 1]);
    }
    cout << p[N - 1] << '\n';
}