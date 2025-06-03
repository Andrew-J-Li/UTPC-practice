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
        ll n, q; cin >> n >> q;
        string s; cin >> s;
        ll c_count = 0;
        for (ll i = 0; i < s.size(); ++i) if (s[i] == 'c') c_count++;
        vector<ll> c_to_a (q);
        vector<pair<char, char>> queries (q);
        for (ll i = 0; i < q; ++i) cin >> queries[i].first >> queries[i].second;
        for (ll i = q - 1; i >= 0; --i) {
            c_to_a[i] = (i == q - 1) ? 0 : c_to_a[i + 1];
            if (queries[i].first == 'c' && queries[i].second == 'a') c_to_a[i]++;
        }
        ll b1 = 0, c1 = 0;
        while (s[b1] != 'b' && b1 < s.size()) b1++;
        while (s[c1] != 'c' && c1 < s.size()) c1++;
        deque<ll> new_b, new_c;
        for (ll i = 0; i < q; ++i) {
            if (queries[i].first == 'a') continue;
            if (queries[i].first == 'b' && queries[i].second == 'a' && (b1 < s.size() || new_b.size() != 0)) {
                ll nb = new_b.front();
                if (nb < b1) { s[nb] = 'a'; new_b.pop_front(); }
                else s[b1] = 'a';
                while (s[b1] != 'b' && b1 < s.size()) b1++;
            }
            if (queries[i].first == 'b' && queries[i].second == 'c' && b1 < s.size()) {
                if (c_count + 1 <= c_to_a[i]) {
                    s[b1] = 'c';
                    new_c.push_back(b1);
                    while (s[b1] != 'b' && b1 < s.size()) b1++;
                    c_count++;
                }
            }
            if (queries[i].first == 'c' && queries[i].second == 'a' && (c1 < s.size() || new_c.size() != 0)) {
                ll nc = new_c.front();
                if (nc < c1) { s[nc] = 'a'; new_c.pop_front(); }
                else s[c1] = 'a';
                while (s[c1] != 'c' && c1 < s.size()) c1++;
                c_count--;
            }
            if (queries[i].first == 'c' && queries[i].second == 'b' && c1 < s.size()) {
                s[c1] = 'b';
                new_b.push_back(c1);
                while (s[c1] != 'c' && c1 < s.size()) c1++;
                c_count--;
            }
        }
        cout << s << endl;
    }
    return 0;
}