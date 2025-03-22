#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int a = 0; a < t; a++) {
        int n; cin >> n;
        vector<int> nums (n);
        vector<pair<int, int>> arr;
        bool no_zero = true;
        bool all_zero = true;
        int ozc = 0;
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
            if (nums[i] != 0) all_zero = false;
            else {
                no_zero = false;
                ozc++;
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) arr.push_back({nums[i], i});
            else {
                if (i == n - 1 || nums[i + 1] != 0) {
                    arr.push_back({nums[i], i});
                }
            }
        }

        if (all_zero) {
            cout << 3 << "\n";
            cout << 1 << " " << n / 2 << "\n";
            cout << 2 << " " << ceil((double) n / 2) + 1 << "\n";
            cout << 1 << " " << 2 << "\n";
        } else if (no_zero) {
            cout << 1 << "\n";
            cout << 1 << " " << n << "\n";
        } else {
            int zc = 0;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i].first == 0) {
                    zc++;
                }
            }
            vector<pair<int, int>> ops;
            if (zc == 1) {
                if (ozc == 1) {
                    cout << 2 << endl;
                    for (int i = 0; i < arr.size(); i++) {
                        if (arr[i].first == 0) {
                            if (i == n - 1) {
                                cout << n - 1 << " " << n << endl;
                            } else {
                                cout << i + 1 << " " << i + 2 << endl;
                            }
                            arr.erase(arr.begin() + i);
                            n--;
                        }
                    }
                    cout << 1 << " " << n << endl;
                    continue;
                } else {
                    cout << 2 << endl;
                    bool done = false;
                    int subi = 0;
                    for (int i = 0; i < arr.size(); i++) {
                        if (done) {
                            arr[i].second -= subi;
                            continue;
                        }
                        if (arr[i].first == 0) {
                            arr[i].first = 1;
                            int temp = arr[i].second;
                            arr[i].second = (i == 0) ? 0 : arr[i - 1].second + 1;
                            cout << arr[i].second + 1 << " " << temp + 1 << endl;
                            temp -= arr[i].second;
                            subi = temp;
                            n -= subi;
                            done = true;
                        }
                    }
                    cout << 1 << " " << n << endl;
                    continue;
                }
            }
            int idx = 0;
            bool in_zero = false;
            for (int i = 0; i < arr.size(); i++) {
                if (arr[i].first == 0) {
                    if (i != 0) {
                        idx = arr[i].second;
                        break;
                    }
                    in_zero = true;
                    continue;
                }
                if (in_zero) {
                    idx = arr[i].second;
                    break;
                }
            }

            ops.push_back({1, idx + 1});
            ops.push_back({2, n - idx});
            ops.push_back({1, 2});

            cout << ops.size() << endl;
            for (int i = 0; i < ops.size(); i++) {
                cout << ops[i].first << " " << ops[i].second << endl;
            }
        }
    }
}