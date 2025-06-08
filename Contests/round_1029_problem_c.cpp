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
        vector<ll> nums (n);
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        unordered_set<ll> curr;
        map<ll, bool> ct;
        unordered_set<ll> prox;
        map<ll, bool> nx;
        curr.insert(nums[0]);
        ct[nums[0]] = true;
        ll rslt = 1;
        for (ll i = 1; i < n; ++i) {
            if (ct[nums[i]] && curr.count(nums[i])) {
                curr.erase(nums[i]);
                prox.insert(nums[i]);
                nx[nums[i]] = true;
                if (curr.empty()) {
                    curr = prox;
                    ct = nx;
                    nx.clear();
                    prox.clear();
                    rslt++;
                }
                continue;
            }
            if (!ct[nums[i]]) {
                prox.insert(nums[i]);
                nx[nums[i]] = true;
            }
        }
        cout << rslt << endl;
    }
    return 0;
}