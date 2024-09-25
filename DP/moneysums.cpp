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
    int n;
    cin >> n;
    vector<int> c(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        sum += c[i];
    }

    vector<int> p(sum + 1, 0);
    p[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sum; j++) {
            if (p[j] == 2) {
                p[j]--;
                continue;
            }
            if (j + c[i] > sum) {
                continue;
            } 
            if (p[j] == 1 && p[j + c[i]] != 1) {
                p[j + c[i]] = 2;
            }
        }
    }

    int count = 0;
    string str = "";
    for (int i = 1; i < sz(p); i++) {
        if (p[i] == 1 || p[i] == 2) {
            count++;
            str += std::to_string(i) + " ";
        }
    }
    cout << count << '\n';
    cout << str << '\n';
}