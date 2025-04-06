#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int temp; cin >> temp;
        mp[temp]++;
    }
    int rslt = 0;
    for (auto& it : mp) {
        if (it.second >= 2) { 
            int val = it.second / 2;
            it.second = it.second % 2;
            mp[it.first + 1] += val;
        }
        if (it.second == 1) rslt++;
    }
    cout << rslt << endl;
}