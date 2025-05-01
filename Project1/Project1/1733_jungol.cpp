#include <bits/stdc++.h>
using namespace std;

int board[19][19];
//8방위까진 필요없네? 아래 대각이랑 오른쪽만 보면 됨.
int dx[4] = { 1,1,1,0 };
int dy[4] = { -1,0,1,1 };
int flag;
void check(int x, int y, int color) {
    int dir;
    for (dir = 0; dir < 4; dir++) {
        int cnt = 1;
        int nx = x + dx[dir], ny = y + dy[dir];
        while (!(nx < 0 || nx >= 19 || ny < 0 || ny >= 19 || color != board[nx][ny])) {
            cnt++;
            nx += dx[dir], ny += dy[dir];
        }
        nx = x - dx[dir], ny = y - dy[dir];
        while (!(nx < 0 || nx >= 19 || ny < 0 || ny >= 19 || color != board[nx][ny])) {
            cnt++;
            nx -= dx[dir], ny -= dy[dir];
        }
        if (cnt == 5) {
            flag = 1;
            cout << board[x][y] << "\n";
            if (dir == 0)
                cout << x + 5 << " " << y - 3;
            else
                cout << x + 1 << " " << y + 1;
            break;
        }
    }
}

int main(void) {
    for (int i = 0; i < 361; i++) {
        int x = i / 19;
        int y = i % 19;
        cin >> board[x][y];
    }
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < 19; j++) {
            if (board[i][j] != 0) {
                check(i, j, board[i][j]);
                if (flag == 1) {
                    return 0;
                }
            }
        }
    }
    cout << 0 << "\n";
    return 0;
}