#include <iostream>
#include <string>
using namespace std;

int board[10][10];
int row[9][10];
int col[9][10];
int blo[3][3][10];
//남은 칸수
int cnt = 81;
int flag;
void print_answer() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void sudoku(int x, int y) {
    if (cnt == 0) {
        print_answer();
        flag = 1;
        return;
    }
    int nexti, nextj = 0;
    if (board[x][y] != 0) {
        nextj = y + 1;
        nexti = nextj == 9 ? x + 1 : x;
        sudoku(nexti, nextj % 9);
    }
    else {
        for (int i = 1; i < 10; i++) {
            if (row[x][i] == 0 && col[y][i] == 0 && blo[x / 3][y / 3][i] == 0) {
                row[x][i] = 1;col[y][i] = 1;blo[x / 3][y / 3][i] = 1;
                cnt--;
                board[x][y] = i;
                nextj = y + 1;
                nexti = nextj == 9 ? x + 1 : x;
                sudoku(nexti, nextj % 9);
                if (flag == 1) return;
                board[x][y] = 0;
                row[x][i] = 0;col[y][i] = 0;blo[x / 3][y / 3][i] = 0;
                cnt++;
            }
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
                blo[i / 3][j / 3][board[i][j]] = 1;
            }
        }
    }
    sudoku(0, 0);
}