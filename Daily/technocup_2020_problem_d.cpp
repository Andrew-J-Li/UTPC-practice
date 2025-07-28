#include <bits/stdc++.h>
#define endl "\n"
#define MOD 1000000007LL
using namespace std;

const int MAX_N = 100000;

struct HASH {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(const vector<pair<int, int>>& vec) const {
        uint64_t result = vec.size();
        for (const auto& [a, b] : vec) {
            uint64_t h = splitmix64(a) ^ (splitmix64(b) << 1);
            result ^= h + 0x9e3779b9 + (result << 6) + (result >> 2);
        }
        return result;
    }
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k; cin >> n >> k;

    int max_div[MAX_N + 1] = {};
    for (int i = 2; i <= MAX_N; ++i) {
        if (max_div[i] == 0) {
            for (int j = i; j <= MAX_N; j += i) max_div[j] = i;
        }
    }

    unordered_map<vector<pair<int, int>>, int, HASH> mp;
    long long rslt = 0;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        vector<pair<int, int>> l;
        vector<pair<int, int>> lp;
        while (x != 1) {
            int p = max_div[x];
            pair<int, int> curr = {p, 0};
            while (x % p == 0) {
                x /= p;
                curr.second++;
            }
            curr.second %= k;
            if (curr.second == 0) continue;
            l.push_back(curr);
            lp.push_back({p, k - curr.second});
        }
        if (l.empty()) {
            l.push_back({0, 0});
            lp.push_back({0, 0});
        }
        auto it = mp.find (lp);
        if (it != mp.end()) rslt += (long long) it->second;
        mp[l]++;
    }

    cout << rslt << endl;
    return 0;
}