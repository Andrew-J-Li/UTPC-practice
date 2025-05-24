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
        vector<int> arr (n);
        for (int i = 0 ; i < n; ++i) {
            cin >> arr[i];
        }
        sort (arr.begin(), arr.end());
        int rslt = INT_MAX;
        int lo = 0, hi = arr.size() - 1; 
        while (lo < arr.size()) {
            if (arr[lo] % 2 != 0) lo++;
            else break;
        }
        while (hi >= 0) {
            if (arr[hi] % 2 != 0) hi--;
            else break;
        }
        rslt = min(rslt, (int) (arr.size() - 1 - hi + lo));
        lo = 0, hi = arr.size() - 1;
        while (lo < arr.size()) {
            if (arr[lo] % 2 != 1) lo++;
            else break;
        }
        while (hi >= 0) {
            if (arr[hi] % 2 != 1) hi--;
            else break;
        }
        rslt = min(rslt, (int) (arr.size() - 1 - hi + lo));
        cout << rslt << endl;
    }
    return 0;
}