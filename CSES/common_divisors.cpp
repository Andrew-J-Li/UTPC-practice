#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define MOD 1000000007LL
using namespace std;

void divisors (ll& rslt, bool* good, const vector<pair<ll, ll>>& fact, ll n, ll i) {
    ll j, x, k;
    for (j = i; j < (ll) fact.size(); ++j) {
        x = fact[j].first * n;
        for (k = 0; k < fact[j].second; ++k) {
            if (good[x]) rslt = max (rslt, x);
            good[x] = true;
            divisors (rslt, good, fact, x, j + 1);
            x *= fact[j].first;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n, mx = 0; cin >> n;
    ll nums[n];
    for (ll i = 0; i < n; ++i) {
        cin >> nums[i];
        mx = max (mx, nums[i]);
    }

    int max_div[mx + 1];
    memset (max_div, 0, sizeof(max_div));
    for (ll i = 2; i <= mx; ++i) {
        if (max_div[i] == 0) {
            for (ll j = i; j <= mx; j += i) {
                max_div[j] = i;
            }
        }
    }
   
    ll rslt = 1;
    bool good[mx + 1];
    memset (good, 0, sizeof(good));
    for (ll i = 0; i < n; ++i) {
        ll curr = nums[i];

        vector<pair<ll, ll>> fact;
        while (curr != 1) {
            ll p = max_div[curr], ct = 0;
            while (curr % p == 0) {
                ct++;
                curr /= p;
            }
            fact.push_back({p, ct});
        }

        divisors (rslt, good, fact, 1, 0);
    }
    cout << rslt << endl;
    return 0;
}