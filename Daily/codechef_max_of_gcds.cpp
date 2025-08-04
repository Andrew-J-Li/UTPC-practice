#include <bits/stdc++.h>
#define ll long long
#define endl "\n"

using namespace std;
const ll MAX_N = 1000;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll max_div[MAX_N + 1];
    memset(max_div, 0, sizeof(max_div));
    for (ll i = 2; i <= MAX_N; ++i) {
        if (max_div[i] == 0) {
            for (ll j = i; j <= MAX_N; j += i) {
                max_div[j] = i;
            }
        }
    }
    
    ll T; cin >> T;    
    while (T--) {
        ll n; cin >> n;
        ll nums[n];
        for (ll i = 0; i < n; ++i) cin >> nums[i];
        
        ll rslt[n];
        memset (rslt, -1, sizeof(rslt));
        unordered_set<ll> divs;
        
        for (ll i = 2; i <= MAX_N; ++i) {
            if (max_div[i] != i) {
                bool cont = false;
                ll curr = i;
                while (curr != 1) {
                    ll p = max_div[curr];
                    while (curr % p == 0) curr /= p;
                    if (divs.count(p) == 0) { cont = true; break; }
                }
                if (cont) continue;
            }
            
            bool add_div = false;
            ll ct = 0;
            for (ll j = 0; j < n; ++j) {
                if (nums[j] % i == 0) {
                    add_div = true;
                    ct++;
                    rslt[ct - 1] = max(rslt[ct - 1], i);
                } else {
                    ct = 0;
                }
            }
            if (add_div) divs.insert(i);
        }

        ll ct = 0, prev = nums[0];
        rslt[ct] = max(rslt[ct], prev);
        for (ll i = 1; i < n; ++i) {
            if (nums[i] == prev) ct++;
            else { ct = 0; prev = nums[i]; }
            rslt[ct] = max(rslt[ct], prev);
        }
        
        for (ll i = 0; i < n; ++i) {
            if (rslt[i] == -1) cout << 1 << " ";
            else cout << rslt[i] << " ";
        }
        cout << endl;
    }
}