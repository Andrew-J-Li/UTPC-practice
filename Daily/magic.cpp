#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    auto compare = [](pair<int, int> a, pair<int, int> b) {
        if ((a.first / a.second) != (b.first / b.second)) return (a.first / a.second) > (b.first / b.second);
        return (a.second - (a.first % a.second)) > (b.second - (b.first % b.second));
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> stuff(compare);
    vector<int> temp (n);
    for (int i = 0; i < n; i++) cin >> temp[i];
    for (int i = 0; i < n; i++) {
        int goof; cin >> goof;
        pair<int, int> curr = {goof, temp[i]};
        stuff.push(curr);
    }
    while (k > 0) {
        pair<int, int> curr = stuff.top();
        int cv = curr.second - (curr.first % curr.second);
        stuff.pop();
        if (k >= cv) {
            k -= cv;
            curr.first += cv;
            stuff.push(curr);
        } else {
            stuff.push(curr);
            break;
        }
    }
    pair<int, int> curr = stuff.top();
    int rslt = curr.first / curr.second;
    cout << rslt << endl;
}