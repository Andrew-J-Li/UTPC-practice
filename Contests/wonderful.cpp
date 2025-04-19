#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    for (int a = 0; a < t; ++a) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> lt (n);
        vector<int> gt (n);
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '<') lt[i + 1]++;
            lt[i + 1] += lt[i];
            if (s[i] == '>') gt[i + 1]++;
            gt[i + 1] += gt[i];
        }

        vector<int> rslt;
        rslt.push_back(lt[n - 1] + 1);
        for (int i = 1; i < n; ++i) {
            if (s[i - 1] == '<') {
                rslt.push_back((lt[n - 1] + 1) - lt[i]);
            } else {
                rslt.push_back((lt[n - 1] + 1) + gt[i]);
            }
        }
        for (int i : rslt) cout << i << " ";
        cout << endl;
    }
}