#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main() {
    ll n; cin >> n;
    map<ll, ll> cards;
    ll rslt = 0;
    for (ll i = 0; i < n; ++i) {
        ll temp; cin >> temp;
        auto it = cards.lower_bound(temp);
        while (it != cards.end()) {
            rslt += it->second * (it->first + temp);
            it = next(it);
        }
        cards[temp]++;
    }
    cout << rslt << endl;
}