#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int rslt = 0;
        for (int j = 1; j * j <= x; j++) {
            if (x % j == 0) {
                if (j * j == x) {
                    rslt++;
                } else {
                    rslt += 2;
                }
            }
        }
        cout << rslt << '\n';
    }
}