#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        string s; cin >> s;
        vector<ll> days;
        for (ll i = n - 1; i >= 0; --i) {
            if (s[i] == '1') days.push_back(i + 1);
        }
        ll lo = 1, hi = n, rslt = 0, sub = 0, rem = 0;
        for (ll i = 0; i < days.size(); ++i) {
            if (lo > hi) break;
            if (lo == hi) { rslt += lo; break; }
            if (lo + 1 == hi) {
                rslt += lo;
                break;
            }
            ll nx = (i == days.size() - 1) ? 0 : days[i + 1];
            if (nx == hi - 1) {
                rslt += lo;
                sub++;
                rem += lo;
                lo++;
                hi--;
                continue;
            }
            ll add = ((hi - 1 - nx) * (hi - nx)) / 2;
            add += (hi - 1 - nx) * nx;
            rslt += add;
            lo -= min(sub, (hi - 1 - nx) - sub);
            rslt -= rem;
            hi = nx;
            sub = 0;
            rem = 0;
        }
        cout << rslt << endl;
    }
    return 0;
}