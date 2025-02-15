#include <iostream>
#include <vector>

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

        int b = 0;
        cin >> b;
        if (num_less == 0) {
            cout << "YES\n";
            continue;
        }

        bool bad = false;
        for (int j = 0; j < N; j++) {
            if (j != 0 && v[j] < v[j - 1]) {
                if (b - v[j] >= v[j - 1]) v[j] = b - v[j];
                else {
                    cout << "NO\n";
                    bad = true;
                    break;
                }
            } else {
                if (j == 0 || b - v[j] >= v[j - 1]) {
                    v[j] = min(b - v[j], v[j]);
                }
            }
        }

        if (!bad) cout << "YES\n";
    }
}