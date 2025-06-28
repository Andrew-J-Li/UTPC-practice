#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        string a, b; cin >> a >> b;
        vector<pair<char, ll>> fi;
        for (ll i = 0; i < a.size(); ++i) {
            if (!fi.empty() && fi[fi.size() - 1].first == a[i]) fi[fi.size() - 1].second++;
            else fi.push_back({a[i], 1});
        }
        vector<pair<char, ll>> se;
        for (ll i = 0; i < b.size(); ++i) {
            if (!se.empty() && se[se.size() - 1].first == b[i]) se[se.size() - 1].second++;
            else se.push_back({b[i], 1});
        }
        if (fi.size() != se.size()) { cout << "NO" << endl; continue; }
        bool valid = true;
        for (ll i = 0; i < fi.size(); ++i) {
            if (fi[i].first != se[i].first) { valid = false; break; }
            ll mn = (se[i].second / 2) + (se[i].second & 1), mx = se[i].second;
            if (!(fi[i].second >= mn && fi[i].second <= mx)) { valid = false; break; }
        }
        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}