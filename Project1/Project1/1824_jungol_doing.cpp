#include <iostream>
#include <string>

int board[10][10];
int row[9][10];
int col[9][10];
int blo[3][3][10];
//남은 칸수
int cnt = 81;
int flag;
void sudoku(int x, int y, int num) {
    if (cnt == 0) {
        flag = 1;
        return;
    }
    if (row[x][num] || col[y][num] || blo[x % 3][y % 3][num])
        return;

    for (int i = x; i < 9; i++) {
        for (int j = y; j < 9; j++) {
            sudoku(i, j);
            if (flag == 1) return;
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int N;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> board[i][j];
            if (board[i][j]) {
                cnt--;
                row[i][board[i][j]] = 1;
                col[j][board[i][j]] = 1;
                blo[i % 3][j % 3][board[i][j]] = 1;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == 0) {
                for (int k = 1; k < 10; k++) {
                    sudoku(i, j, k);

                }
            }
        }
    }
}