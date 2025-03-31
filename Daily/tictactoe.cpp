#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<vector<vector<string>>> board (3, vector<vector<string>>(3));
    int x, y;
    string temp;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cin >> temp;
                board[i][k].push_back(temp);
            }
        }
    }
    cin >> x >> y;
    int gx = ((x % 3) == 0) ? 2 : (x % 3) - 1;
    int gy = ((y % 3) == 0) ? 2 : (y % 3) - 1;
    bool empty = false;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[gx][gy][i][j] == '.') {
                empty = true;
                break;
            }
        }
    }
    if (empty) {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[gx][gy][i][j] == '.') {
                    board[gx][gy][i][j] = '!';
                }
            }
        }
    } else {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    for (int l = 0; l < 3; ++l) {
                        if (board[i][j][k][l] == '.') board[i][j][k][l] = '!';
                    }
                }
            }
        }
    }

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 3; ++k) {
                cout << board[i][k][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
}