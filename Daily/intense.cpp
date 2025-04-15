#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;
    vector<double> temp (n);
    vector<double> ps (n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> temp[i];
        ps[i + 1] = ps[i] + temp[i];
    }
    double rslt = -1;
    for (double i = k; i <= n; ++i) {
        for (double j = 0; j + i <= n; ++j) {
            double curr = ps[j + i] - ps[j];
            curr /= i;
            rslt = max(curr, rslt);
        }
    }
    cout << setprecision(15) << rslt << endl;
}