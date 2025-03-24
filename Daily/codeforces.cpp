#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
int main(){
    long long k;
    cin >> k;
    string s = "codeforces";
    vector<long long> cnt(10, 1);
    long long prod = 1;
    for (int i = 0; i < 10; i++)
        prod *= cnt[i];
    int index = 0;
    while (prod < k) {
        prod /= cnt[index];
        cnt[index]++;
        prod *= cnt[index];
        index = (index + 1) % 10;
    }
    string ans;
    for (int i = 0; i < 10; i++){
        ans.append(cnt[i], s[i]);
    }
    cout << ans << "\n";
    return 0;
}
