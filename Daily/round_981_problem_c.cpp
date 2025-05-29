#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> nums (n);
        for (int i = 0; i < n; ++i) cin >> nums[i];
        for (int i = 1; i < n / 2; ++i) {
            if (nums[i - 1] == nums[i] || nums[n - i - 1] == nums[n - i]) swap(nums[i], nums[n - i - 1]);
        }
        int seq = 1, prev = -1, rslt = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == prev) { seq++; continue; }
            else rslt += seq - 1;
            prev = nums[i];
            seq = 1;
        }
        rslt += seq - 1;
        cout << rslt << endl;
    }
    return 0;
}