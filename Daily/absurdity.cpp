#include <bits/stdc++.h>

using namespace std;

int main() {
    long long n, k; cin >> n >> k;
    vector<long long> nums(n);
    vector<long long> ps(n + 1);
    vector<pair<long long, long long>> dp(n);
    for (long long i = 0; i < n; ++i) {
        cin >> nums[i];
        ps[i + 1] = nums[i] + ps[i];
    }
    long long m = 0, m1 = 0, m2 = 0;
    for (long long i = n - k - 1; i - k + 1 >= 0; --i) {
        long long left = ps[i + 1] - ps[i - k + 1];
        long long right = ps[i + k + 1] - ps[i + 1];
        if (right >= dp[i + 1].first) dp[i].second = i + 1;
        else dp[i].second = dp[i + 1].second;
        dp[i].first = max(right, dp[i + 1].first);
        if (dp[i].first + left >= m) {
            m1 = i - k + 1;
            m2 = dp[i].second;
        }
        m = max(m, dp[i].first + left);
    }
    cout << m1 + 1 << " " << m2 + 1 << endl;
}