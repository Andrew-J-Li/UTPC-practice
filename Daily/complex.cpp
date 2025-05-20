#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> sieve (1000001);
    sieve[1] = true;
    for (ll i = 4; i < sieve.size(); i += 2) sieve[i] = true;
    for (ll i = 3; i < sieve.size(); i += 2) {
        if (!sieve[i]) for (ll a = i * i; a < sieve.size(); a += i) sieve[a] = true;
    }

    int t; cin >> t;
    while (t--) {
        ll n, e; cin >> n >> e;
        vector<ll> arr (n);
        ll rslt = 0;
        vector<pair<ll, ll>> group (n);
        for (ll i = 0; i < n; ++i) cin >> arr[i];
        for (ll i = 0; i < n; ++i) {
            if (arr[i] == 1) {
                if (i - e < 0) group[i].first = 1;
                else {
                    group[i] = group[i - e];
                    if (group[i - e].second != 0) group[i].second++;
                    else group[i].first++;
                    if (group[i].second != 0) rslt += 1 + group[i].first;
                }
                continue;
            }
            if (!sieve[arr[i]]) {
                if (i - e < 0) group[i].second = 1;
                else {
                    group[i] = group[i - e];
                    if (group[i].second != 0) {
                        group[i].first = group[i].second - 1;
                        group[i].second = 1;
                    } else {
                        group[i].second = 1;
                    }
                }
                if (!(group[i].second == 1 && group[i].first == 0)) rslt += group[i].first;
                continue;
            }
            group[i].first = 0;
            group[i].second = 0;
        }
        cout << rslt << endl;
    }
}