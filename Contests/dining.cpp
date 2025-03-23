#include <bits/stdc++.h>

using namespace std;

vector<pair<pair<int, int>, int>> seats;

bool comp (pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
    int ad = a.first.first + a.first.second;
    int bd = b.first.first + b.first.second;
    if (a.first.first % 3 == 2 && a.first.second % 3 == 2) ad += 2;
    if (b.first.first % 3 == 2 && b.first.second % 3 == 2) bd += 2;
    if (ad == bd) {
        return (a.first.first == b.first.first) ? a.first.second < b.first.second : a.first.first < b.first.first;
    } else {
        return ad < bd;
    }
}

void precompute (int n) {
    int sq = 0;
    bool going = true;
    while (going) {
        int parity = 0;
        for (int temp = sq * sq; temp < (sq + 1) * (sq + 1); ++temp) {
            if (temp >= n) {
                going = false;
                break;
            }
            if (temp + 1 == (sq + 1) * (sq + 1)) {
                seats.push_back({{3 * sq + 1, 3 * sq + 1}, temp});
                seats.push_back({{3 * sq + 2, 3 * sq + 1}, temp});
                seats.push_back({{3 * sq + 1, 3 * sq + 2}, temp});
                seats.push_back({{3 * sq + 2, 3 * sq + 2}, temp});
            } else if (parity % 2 == 0) {
                seats.push_back({{3 * (parity / 2) + 1, 3 * sq + 1}, temp});
                seats.push_back({{3 * (parity / 2) + 2, 3 * sq + 1}, temp});
                seats.push_back({{3 * (parity / 2) + 1, 3 * sq + 2}, temp});
                seats.push_back({{3 * (parity / 2) + 2, 3 * sq + 2}, temp});
            } else {
                seats.push_back({{3 * sq + 1, 3 * (parity / 2) + 1}, temp});
                seats.push_back({{3 * sq + 2, 3 * (parity / 2) + 1}, temp});
                seats.push_back({{3 * sq + 1, 3 * (parity / 2) + 2}, temp});
                seats.push_back({{3 * sq + 2, 3 * (parity / 2) + 2}, temp});
            }
            ++parity;
        }
        ++sq;
    }

    sort(seats.begin(), seats.end(), comp);
}

int main() {
    int t; cin >> t;
    precompute (50000);

    for (int a = 0; a < t; a++) {
        int n; cin >> n;
        vector<int> pref (n);
        vector<bool> taken (200000, false);
        vector<bool> taktable (50000, false);
        for (int i = 0; i < n; ++i) cin >> pref[i];
        int curr_seat = 0;
        int table_idx = 0;
        for (int i = 0; i < n; ++i) {
            if (pref[i] == 0) {
                while (taktable[seats[table_idx].second]) table_idx++;
                taken[table_idx] = true;
                taktable[seats[table_idx].second] = true;
                pair<int, int> curr = seats[table_idx].first;
                cout << curr.first << " " << curr.second << endl;
                continue;
            }
            while (taken[curr_seat]) curr_seat++;
            pair<int, int> curr = seats[curr_seat].first;
            cout << curr.first << " " << curr.second << endl;
            taktable[seats[curr_seat].second] = true;
            taken[curr_seat] = true;
        }
    }
}