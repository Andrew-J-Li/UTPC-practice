#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;


int main() {
    ull n;
    string a;
    cin >> n >> a;
    vector<int> p (10, 0);

    for (int i = 0; i < n; i++) {
        if (a[i] == '2') p[2]++;
        else if (a[i] == '3') p[3]++;
        else if (a[i] == '4') p[3]++, p[2] += 2;
        else if (a[i] == '5') p[5]++;
        else if (a[i] == '6') p[5]++, p[3]++;
        else if (a[i] == '7') p[7]++;
        else if (a[i] == '8') p[7]++, p[2] += 3;
        else if (a[i] == '9') p[7]++, p[2]++, p[3] += 2;
    }

    for (int i = 9; i >= 0; i--) {
        while (p[i] > 0) {
            cout << i;
            p[i]--;
        }
    }
}