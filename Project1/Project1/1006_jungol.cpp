#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

//1~100
bool board[101][101];
int vis[101][101][4];
int dir[4] = { 1,3,2,4 };//동남서북
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    //go k 123
    //turn left right
    int M, N;
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    }
    int stx, sty, std, edx, edy, edd;
    cin >> stx >> sty >> std >> edx >> edy >> edd;
    queue<tuple<int, int, int>> q;
    q.push({ stx,sty,std });
    vis[stx][sty][std] = 1;
    while (!q.empty()) {
        auto [curx, cury, curd] = q.front();
        q.pop();
        if (curx == edx && cury == edy && curd == edd) {
            cout << vis[curx][cury][curd] - 1;
            return 0;
        }
        for (int i = 0; i < 5; i++) {
            int nxtx = curx, nxty = cury, nxtd = curd;
            if (i == 0) {
                //dir = right
                for (int i = 0; i < 4; i++) {
                    if (nxtd == dir[i]) {
                        nxtd = dir[(i + 1) % 4];
                        break;
                    }
                }
            }
            else if (i == 1) {
                //dir = left
                for (int i = 0; i < 4; i++) {
                    if (nxtd == dir[i]) {
                        nxtd = dir[(i + 3) % 4];
                        break;
                    }
                }
            }
            else {
                int flag = 0;
                //i>=2
                if (nxtd == 1) {
                    //cury+1 ~ cury+i-1 까지 확인
                    for (int j = nxty + 1; j < nxty + i; j++) {
                        if (j > N || board[nxtx][j]) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) {
                        continue;
                    }
                    else {
                        nxty = nxty + i - 1;
                    }
                }
                else if (nxtd == 3) {
                    for (int j = nxtx + 1; j < nxtx + i; j++) {
                        if (j > M || board[j][nxty]) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) {
                        continue;
                    }
                    else {
                        nxtx = nxtx + i - 1;
                    }
                }
                else if (nxtd == 2) {
                    for (int j = nxty - 1; j > nxty - i; j--) {
                        if (j <= 0 || board[nxtx][j]) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) {
                        continue;
                    }
                    else {
                        nxty = nxty - i + 1;
                    }
                }
                else {
                    for (int j = nxtx - 1; j > nxtx - i; j--) {
                        if (j <= 0 || board[j][nxty]) {
                            flag = 1;
                            break;
                        }
                    }
                    if (flag == 1) {
                        continue;
                    }
                    else {
                        nxtx = nxtx - i + 1;
                    }
                }
                if (flag == 1) {
                    continue;
                }
            }
            if (vis[nxtx][nxty][nxtd] != 0) continue;
            vis[nxtx][nxty][nxtd] = vis[curx][cury][curd] + 1;
            q.push({ nxtx,nxty,nxtd });
        }
    }

    cout << "-1";
    return 0;
}