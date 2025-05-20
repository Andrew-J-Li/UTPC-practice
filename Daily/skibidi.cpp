#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;
 
ll coords (ll x, ll y, ll n) {
    if (n == 1) {
        if (x == 1 && y == 1) return (ll) 1;
        if (x == 2 && y == 2) return (ll) 2;
        if (x == 2 && y == 1) return (ll) 3;
        if (x == 1 && y == 2) return (ll) 4;
    }
    ll size = 1LL << n;
    ll dx = (1LL << (2*(n-1)));
    if (x <= size / 2 && y <= size / 2) return coords(x, y, n - 1);
    else if (x > size / 2 && y > size / 2) return dx + coords(x - size / 2, y - size / 2, n - 1);
    else if (x > size / 2 && y <= size / 2) return 2 * dx + coords(x - size / 2, y, n - 1);
    else return 3 * dx + coords(x, y - size / 2, n - 1);
}
 
pair<ll, ll> nums (ll val, ll n) {
    if (n == 1) {
        if (val == 1) return {1, 1};
        if (val == 2) return {2, 2};
        if (val == 3) return {2, 1};
        if (val == 4) return {1, 2};
    }
    ll size = 1LL << n;
    ll mid = (1LL << (2*(n-1)));
    if (val <= mid) return nums(val, n - 1);
    else if (val <= mid * 2) {
        ll x = (size / 2);
        ll y = (size / 2);
        pair<ll, ll> nx = nums(val - (mid), n - 1);
        return {x + nx.first, y + nx.second};
    } else if (val <= mid * 3) {
        ll x = (size / 2);
        pair<ll, ll> nx = nums(val - (mid * 2), n - 1);
        return {x + nx.first, nx.second};
    } else {
        ll y = (size / 2);
        pair<ll, ll> nx = nums(val - (mid * 3), n - 1);
        return {nx.first, y + nx.second};
    }
}
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        ll q; cin >> q;
        for (int i = 0; i < q; ++i) {
            string s; cin >> s;
            if (s == "->") {
                ll x, y; cin >> x >> y;
                ll rslt = coords(x, y, n);
                cout << rslt << endl;
            } else {
                ll d; cin >> d;
                pair<ll, ll> rslt = nums (d, n);
                cout << rslt.first << " " << rslt.second << endl;
            }
        }
    }
}