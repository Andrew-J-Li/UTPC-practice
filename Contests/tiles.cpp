#include <bits/stdc++.h>


using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 1) cout << 1 << endl;
    else if (n == 2) cout << 2 << endl;
    else {
        long long temp = n;
        unordered_map<long long, long long> mp;
        for (long long i = 2; i * i <= temp; i++) {
            while (temp % i == 0) {
                temp /= i;
                mp[i]++;
                if (mp.size() >= 2) break;
            }
            if (mp.size() >= 2) break;
        }
        if (temp > 2) mp[temp]++;
        if (mp.size() == 1) {
            for (const auto& a : mp) {
                cout << a.first << endl;
            }
        } else {
            cout << 1 << endl;
        }
    }
}