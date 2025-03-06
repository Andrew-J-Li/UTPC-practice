#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        mp[temp1]++;
        mp[temp2 + 1]--;
    }

    int ct = 0;
    for (const auto& i : mp) {
        ct += i.second;
        mp[i.first] = ct;
    }

    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;
        auto it = mp.upper_bound(temp);
        if (it == mp.begin()) {
            cout << 0 << endl;
        } else {
            it--;
            cout << it->second << endl;
        }
    }

    return 0;
}