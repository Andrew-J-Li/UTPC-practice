#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<pair<int, int>> ran(n);

    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        ran[i] = make_pair(temp1, temp2);
    }

    sort(ran.begin(), ran.end());

    for (int i = 0; i < q; i++) {
        int temp;
        cin >> temp;

        int lo = 0, hi = ran.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (ran[mid].first > temp) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        if (ran[lo].first <= temp) lo++;

        vector<pair<int, int>> e (ran.begin(), ran.begin() + lo);
        sort(e.begin(), e.end(), [](auto &left, auto &right) {
            return left.second < right.second;
        });

        lo = 0, hi = e.size() - 1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (e[mid].second > temp) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        // if (e[hi].second >= temp) hi++;
        // cout << e.size() - hi << endl;
    }
}