#include <bits/stdc++.h>
#define endl "\n"
# define M_PI 3.14159265358979323846
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(9);

    int t; cin >> t;
    while (t--) {
        double n; cin >> n;
        n *= 2;
        double ang = (((n - 2) * 180) / n) / 2;
        ang /= 360;
        ang *= (2 * M_PI);
        double h = tan(ang);
        cout << h << endl;
    }
}