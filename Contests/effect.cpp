#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;
 
ll binexp(ll a, ll b) {
    ll r = 1;
    while(b) {
        if(b & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return r;
}
 
void upd(int pos, vector<bool>& bad, int &cnt) {
    for (int d = 1; d * d <= pos; d++) {
        if(pos % d == 0) {
            if(!bad[d]) { bad[d] = true; cnt++; }
            int oth = pos / d;
            if(oth != d && !bad[oth]) { bad[oth] = true; cnt++; }
        }
    }
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<pair<int,int>> v;
    for (int i = 1; i <= n; i++) v.push_back({a[i], i});
    sort(v.begin(), v.end(), greater<pair<int,int>>());
    ll ans = 0;
    int i = 0, cnt = 0;
    vector<bool> bad(n+1, false);
    ll pg = 0;
    int prev = -1;
    while(i < n){
        int cur = v[i].first;
        while(i < n && v[i].first > cur){
            int pos = v[i].second;
            upd(pos, bad, cnt);
            i++;
        }
        ll gcur = (binexp(2, n - cnt) + MOD - 1) % MOD;
        if(prev != -1){
            ll fprev = ((pg + MOD) - gcur) % MOD;
            ans = (ans + ( (ll)prev * fprev )) % MOD;
        }
        prev = cur; pg = gcur;
        while(i < n && v[i].first == cur){
            int pos = v[i].second;
            upd(pos, bad, cnt);
            i++;
        }
    }
    int cur = 0;
    while(i < n && v[i].first > cur){
        int pos = v[i].second;
        upd(pos, bad, cnt);
        i++;
    }
    ll gz = (binexp(2, n - cnt) + MOD - 1) % MOD;
    ll fl = (pg + MOD - gz) % MOD;
    ans = (ans + ((ll)prev * fl)) % MOD;
    cout << ans % MOD << "\n";
    return 0;
}