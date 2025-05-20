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
        ll n; cin >> n;
        int temp = 0;
        cout << "mul 9" << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);

        cout << "digit" << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);

        cout << "digit" << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);

        cout << "digit" << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);

        cout << "digit" << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);

        cout << "digit" << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);

        cout << "add " << n - 9 << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);
        
        cout << "!" << endl;
        cout.flush();
        cin >> temp;
        if (temp == -1) exit(1);
    }
}