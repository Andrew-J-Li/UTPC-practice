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
        string n; cin >> n;
        ll rslt = LLONG_MAX;
        for (ll i = 0; i < n.size(); ++i) {
            string g = n.substr(i, n.size() - i);
            string d (n.size() - i, '9');
            ll ce = 0;
            ll te = stoll(g);
            ll ta = stoll(d);
            while (to_string(te).find('7') == string::npos) {
                ce++;
                te += ta;
            }
            rslt = min(ce, rslt);
            if (i != n.size() - 1) {
                string s = n.substr(i, n.size() - i);
                string ni (n.size() - i - 1, '9');
                ll ct = 0;
                ll temp = stoll(s);
                ll temp_a = stoll(ni);
                while (to_string(temp).find('7') == string::npos) {
                    temp += temp_a;
                    ct++;
                }
                rslt = min(rslt, ct);
            }
        }
        cout << rslt << endl;
    }
    return 0;
}