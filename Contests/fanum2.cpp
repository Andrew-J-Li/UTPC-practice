#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int T = 0;
    cin >> T;

    for (int i = 0; i < T; i++) {
        int N, M;
        cin >> N >> M;

        vector<int> v;
        int num_less = 0;
        for (int j = 0; j < N; j++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
            if (j != 0 && v[j] < v[j - 1]) num_less++;
        }

        vector<int> b;
        for (int j = 0; j < M; j++) {
            int temp;
            cin >> temp;
            b.push_back(temp);
        }

        if (num_less == 0) {
            cout << "YES\n";
            continue;
        }

        sort(b.begin(), b.end());
        bool bad = false;
        for (int j = 0; j < N; j++) {
            if (j != 0 && v[j] < v[j - 1]) {
                int hi = b.size() - 1;
                int lo = 0;
                int b_curr = -1;

                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (b[mid] - v[j] >= v[j - 1]) {
                        hi = mid;
                        b_curr = b[mid];
                    } else {
                        lo = mid + 1;
                    }
                }

                b_curr = (b[lo] - v[j] >= v[j - 1]) ? b[lo] : b_curr;

                if (b_curr == -1) {
                    cout << "NO\n";
                    bad = true;
                    break;
                } else {
                    v[j] = b_curr - v[j];
                }
            } else {
                int prev = (j == 0) ? INT_MIN : v[j - 1];
                int hi = b.size() - 1;
                int lo = 0;
                int b_curr = -1;

                while (lo < hi) {
                    int mid = (lo + hi) / 2;
                    if (b[mid] - v[j] >= prev) {
                        hi = mid;
                        b_curr = b[mid];
                    } else {
                        lo = mid + 1;
                    }
                }

                b_curr = (b[lo] - v[j] >= prev) ? b[lo] : b_curr;
                if (b_curr == -1) continue;
                else if (b_curr - v[j] < v[j]) v[j] = b_curr - v[j];
            }
        }

        if (!bad) cout << "YES\n";
    }
}