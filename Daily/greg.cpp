#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, m, k; cin >> n >> m >> k;
    vector<ll> nums (n);
    vector<pair<pair<ll, ll>, ll>> ops (m);
    map<ll, ll> weights; map<ll, ll> vals;
    for (int i = 0; i < n; ++i) cin >> nums[i];
    for (int i = 0; i < m; ++i) cin >> ops[i].first.first >> ops[i].first.second >> ops[i].second;
    for (int i = 0; i < k; ++i) {
        ll temp_1, temp_2; cin >> temp_1 >> temp_2;
        temp_1--; temp_2--;
        weights[temp_1]++; weights[temp_2 + 1]--;
    }
    ll tot_weight = 0;
    for (auto& it : weights) {
        tot_weight += it.second;
        it.second = tot_weight;
    }
    for (int i = 0; i < m; ++i) {
        auto it = weights.lower_bound(i);
        if (it->first != i) it--;
        vals[ops[i].first.first - 1] += it->second * ops[i].second;
        vals[ops[i].first.second] -= it->second * ops[i].second;
    }
    ll tot = 0;
    for (auto& it : vals) {
        tot += it.second;
        it.second = tot;
    }
    for (int i = 0; i < n; ++i) {
        auto it = vals.lower_bound(i);
        if (it->first != i) it--;
        nums[i] += it->second;
        cout << nums[i] << " ";
    }
    cout << endl;
}