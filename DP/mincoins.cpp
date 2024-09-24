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
    int X;
    cin >> N >> X;
    vector<int> c(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> c[i];
    }

    vector<int> s(X + 1, 1e9);
    s[0] = 0;
    for (int i = 1; i <= X; i++) {
        for (int j = 0; j < N; j++) {
            if (c[j] > i) {
                continue;
            }
            s[i] = min(s[i - c[j]] + 1, s[i]);
        }
    }
    if (s[X] == 1e9) {
        s[X] = -1;
    }
    cout << s[X] << '\n';
}