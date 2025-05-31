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
        map<ll, ll> mp;
        for (ll i = 0; i < n; ++i) {
            ll temp; cin >> temp;
            mp[temp]++;
        }
        vector<pair<ll, ll>> pts;
        ll sum = 0;
        for (const auto& it : mp) {
            if (it.second >= 2) {
                sum += it.second / 2;
                pts.push_back(make_pair(it.first, it.second));
            }
        }
        if (sum < 4) { cout << "NO" << endl; continue; }
        cout << "YES" << endl;
        if (pts.size() == 1) {
            for (ll i = 0; i < 8; ++i) cout << pts[0].first << " ";
            cout << endl;
            continue;
        }
        if (pts.size() == 2) {
            if (pts[0].second >= 4 && pts[1].second >= 4) {
                cout << pts[0].first << " " << pts[0].first << " ";
                cout << pts[0].first << " " << pts[1].first << " ";
                cout << pts[1].first << " " << pts[0].first << " ";
                cout << pts[1].first << " " << pts[1].first << " ";
            } else {
                if (pts[0].second >= pts[1].second) {
                    cout << pts[0].first << " " << pts[0].first << " ";
                    cout << pts[0].first << " " << pts[0].first << " ";
                    cout << pts[0].first << " " << pts[1].first << " ";
                    cout << pts[0].first << " " << pts[1].first << " ";
                } else {
                    cout << pts[1].first << " " << pts[1].first << " ";
                    cout << pts[1].first << " " << pts[1].first << " ";
                    cout << pts[1].first << " " << pts[0].first << " ";
                    cout << pts[1].first << " " << pts[0].first << " ";
                }
            }
            cout << endl;
            continue;
        }
        ll mn1, mn2;
        mn1 = pts[0].first;
        mn2 = (pts[0].second >= 4) ? pts[0].first : pts[1].first;
        ll mx1, mx2;
        mx1 = pts[pts.size() - 1].first;
        mx2 = (pts[pts.size() - 1].second >= 4) ? pts[pts.size() - 1].first : pts[pts.size() - 2].first;
        if ((mx2 - mn1) * (mx1 - mn2) >= (mx1 - mn1) * (mx2 - mn2)) {
            cout << mn1 << " " << mx1 << " ";
            cout << mx2 << " " << mx1 << " ";
            cout << mn1 << " " << mn2 << " ";
            cout << mx2 << " " << mn2 << " ";
        } else {
            cout << mn1 << " " << mx2 << " ";
            cout << mx1 << " " << mx2 << " ";
            cout << mn1 << " " << mn2 << " ";
            cout << mx1 << " " << mn2 << " ";
        }
        cout << endl;
    }
    return 0;
}