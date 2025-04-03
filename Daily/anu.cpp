#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n; cin >> n;
    vector<int> v (n);
    vector<int> ps (n);
    vector<int> os (n);
    for (int i = 0; i < n; ++i) cin >> v[i];
    for (int i = 0; i < n; ++i) ps[i] = ((i == 0) ? 0 : ps[i - 1]) | v[i];
    for (int i = n - 1; i >= 0; --i) os[i] = ((i == n - 1) ? 0 : os[i + 1]) | v[i];
    int mx = 0, idx = 0;
    bool did = false;
    for (int i = 0; i < n; ++i) {
        int tf = (i == 0) ? 0 : ps[i - 1];
        int tb = (i == n - 1) ? 0 : os[i + 1];
        int te = tf | tb;
        if (v[i] - (v[i] & te) > mx) {
            mx = v[i] - (v[i] & te);
            idx = i;
        }
    }
    cout << v[idx] << " ";
    v.erase(v.begin() + idx);
    for (int i : v) {
        cout << i << " ";
    }
    cout << endl;
}