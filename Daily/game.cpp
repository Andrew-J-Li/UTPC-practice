#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

struct cmp {
    bool operator()(const pair<ll,ll>& a, const pair<ll,ll>& b) const {
        return (a.first + a.second) < (b.first + b.second);
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, cmp> pq;
        vector<ll> a (n), b (n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        for (int i = 0; i < n; ++i) cin >> b[i];
        for (int i = 0; i < n; ++i) pq.push({a[i], b[i]});
        int count = 0; ll rslt = 0;
        while (!pq.empty()) {
            pair<ll, ll> curr = pq.top();
            pq.pop();
            if (count % 2 == 0) rslt += curr.first - 1;
            else rslt -= curr.second - 1;
            count++;
        }
        cout << rslt << endl;
    }
}