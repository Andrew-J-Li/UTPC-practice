#include <bits/stdc++.h>
using namespace std;

const int maxn = 2e6 + 100;
int a, cnt[maxn + 10];

int main() {
    std::ios::sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) cin >> a, cnt[a]++;
    int rslt = 0;
    for (int i = 0; i < maxn; ++i) {
        if (cnt[i]) {
            cnt[i + 1] += cnt[i] / 2;
            cnt[i] %= 2;
            if (cnt[i]) ++rslt;
        }
    }
    cout << rslt << endl;
    return 0;
}