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
        map<ll, ll> goof;
        bool good = false;
        for (ll i = 0; i < n; ++i) {
            ll temp; cin >> temp;
            goof[temp]++;
            if (goof[temp] >= 4) good = true;
        }
        pair<ll, bool> prev = {-1, false};
        for (auto const& ele : goof) {
            if (good) break;
            if (prev.first == ele.first - 1 && prev.second && ele.second >= 2) {
                good = true;
                break;
            } else if (prev.first == ele.first - 1 && prev.second && ele.second == 1) {
                prev.first = ele.first;
                prev.second = true;
            } else if (ele.second >= 2) {
                prev.first = ele.first;
                prev.second = true;
            } else {
                prev.first = ele.first;
                prev.second = false;
            }
        }
        cout << (good ? "Yes" : "No") << endl;
    }
}