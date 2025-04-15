#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<double> r1 (n);
    for (int i = 0; i < n; ++i) cin >> r1[i];
    int m; cin >> m;
    vector<double> p1 (m);
    for (int i = 0; i < m; ++i) cin >> p1[i];
    int k; cin >> k;
    vector<double> p2 (k);
    for (int i = 0; i < k; ++i) cin >> p2[i];
    double a, b; cin >> a >> b;

    sort (r1.begin(), r1.end());
    sort (p1.begin(), p1.end());
    sort (p2.begin(), p2.end());
    double r1c = r1[r1.size() - 1];
    double p1c = p1[p1.size() - 1];
    double p2c = p2[0];

    double coeff_a = a * p2c;
    double coeff_b = b * p1c;
    double coeff_right = b * p1c * r1c * r1c;
    double final_coeff_right = coeff_right / (coeff_a + coeff_b);
    double rslt = sqrt(final_coeff_right);
    cout << setprecision(15) << rslt << endl;
}