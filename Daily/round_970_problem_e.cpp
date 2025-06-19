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
        string s; cin >> s;
        if (n == 1) { cout << 1 << endl; continue; }
        if (n & 1) {
            vector<vector<ll>> pse (n, vector<ll>(26));
            for (ll i = 0; i < n; i += 2) {
                if (i != 0) { pse[i] = pse[i - 2]; pse[i - 1] = pse[i - 2]; }
                pse[i][s[i] - 'a']++;
            }
            vector<vector<ll>> pso (n, vector<ll>(26));
            for (ll i = 1; i < n; i += 2) {
                if (i != 1) { pso[i] = pso[i - 2]; pso[i - 1] = pso[i - 2]; }
                pso[i][s[i] - 'a']++;
            }
            pso[n - 1] = pso[n - 2];
            ll curr = 0;
            for (ll i = 0; i < n; ++i) {
                ll fi = 0, se = 0;
                for (ll j = 0; j < 26; ++j) {
                    ll temp1 = 0, temp2 = 0;
                    if (i != 0) temp1 = max(temp1, pse[i - 1][j]);
                    temp2 = max(temp2, pso[n - 1][j] - pso[i][j]);
                    fi = max(fi, temp1 + temp2);
                }
                for (ll j = 0; j < 26; ++j) {
                    ll temp3 = 0, temp4 = 0;
                    if (i != 0) temp3 = max(temp3, pso[i - 1][j]);
                    temp4 = max(temp4, pse[n - 1][j] - pse[i][j]);
                    se = max(se, temp3 + temp4);
                }
                curr = max(curr, fi + se);
            }
            ll rslt = n - curr;
            cout << rslt << endl;
            continue;
        }

        map<char, ll> mp;
        pair<char, ll> mx = {'0', -1};
        ll rslt = 0;
        for (ll i = 0; i < s.size(); i += 2) {
            mp[s[i]]++;
            if (s[i] == mx.first) mx.second++;
            else if (mp[s[i]] > mx.second) {
                mx.first = s[i];
                mx.second = mp[s[i]];
            }
        }
        map<char, ll> mp_2;
        pair<char, ll> mx_2 = {'0', -1};
        for (ll i = 1; i < s.size(); i += 2) {
            mp_2[s[i]]++;
            if (s[i] == mx_2.first) mx_2.second++;
            else if (mp_2[s[i]] > mx_2.second) {
                mx_2.first = s[i];
                mx_2.second = mp_2[s[i]];
            }
        }
        rslt += (n / 2) - mx.second;
        rslt += (n / 2) - mx_2.second;
        cout << rslt << endl;
    }
    return 0;
}