#include <bits/stdc++.h>
#define ll long long
#define MAXN 100005
using namespace std;

ll bit_count[MAXN];
ll bit_sum[MAXN];

void update_count(int idx, ll val, int n) {
    for (; idx <= n; idx += idx & -idx)
        bit_count[idx] += val;
}

void update_sum(int idx, ll val, int n) {
    for (; idx <= n; idx += idx & -idx)
        bit_sum[idx] += val;
}

ll query_count(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit_count[idx];
    return sum;
}

ll query_sum(int idx) {
    ll sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit_sum[idx];
    return sum;
}

int main() {
    ll n;
    cin >> n;
    
    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    
    memset(bit_count, 0, sizeof(bit_count));
    memset(bit_sum, 0, sizeof(bit_sum));
    
    ll result = 0;
    
    for (int i = 0; i < n; ++i) {
        ll greater_count = query_count(n) - query_count(a[i]);
        ll greater_sum = query_sum(n) - query_sum(a[i]);
        
        result += a[i] * greater_count + greater_sum;
        
        update_count(a[i], 1, n);
        update_sum(a[i], a[i], n);
    }
    
    cout << result << endl;
    return 0;
}