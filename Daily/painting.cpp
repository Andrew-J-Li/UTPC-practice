#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, a, b, c, d; cin >> n >> a >> b >> c >> d;
    ll ab, ac, bd, cd; ll rslt = 0;
    if (a + b >= c + d && a + b >= a + c && a + b >= b + d) {
        ab = 1;
        ac = ab + b - c;
        bd = ab + a - d;
        cd = ac + a - d;
        if (ac < 1 || ac > n || bd < 1 || bd > n || cd < 1 || cd > n || ab < 1 || ab > n) rslt = 0;
        else rslt += (n - max(ab, max(ac, max(bd, cd))) + 1);
    } else if (a + c >= c + d && a + c >= a + b && a + c >= b + d) {
        ac = 1;
        ab = ac + c - b;
        bd = ab + a - d;
        cd = ac + a - d;
        if (ac < 1 || ac > n || bd < 1 || bd > n || cd < 1 || cd > n || ab < 1 || ab > n) rslt = 0;
        else rslt += (n - max(ab, max(ac, max(bd, cd))) + 1);
    } else if (b + d >= c + d && b + d >= a + b && b + d >= a + c) {
        bd = 1;
        cd = b + bd - c;
        ab = d + bd - a;
        ac = ab + b - c;
        if (ac < 1 || ac > n || bd < 1 || bd > n || cd < 1 || cd > n || ab < 1 || ab > n) rslt = 0;
        else rslt += (n - max(ab, max(ac, max(bd, cd))) + 1);
    } else {
        cd = 1;
        bd = c + cd - b;
        ab = d + bd - a;
        ac = ab + b - c;
        if (ac < 1 || ac > n || bd < 1 || bd > n || cd < 1 || cd > n || ab < 1 || ab > n) rslt = 0;
        else rslt += (n - max(ab, max(ac, max(bd, cd))) + 1);
    }
    cout << rslt * n << endl;
}