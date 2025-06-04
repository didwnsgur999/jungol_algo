#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int board[101][101];
int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };
queue<pair<int, int>> Q;
void bfs(int stx, int sty, int edx, int edy) {
    board[stx][sty] = 1;
    Q.push({ stx,sty });
    while (!Q.empty()) {
        auto cur = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];
            if (nx < 0 || nx >= N || ny < 0 || ny >= M || board[nx][ny]) continue;
            if (nx == edx && ny == edy) {
                cout << board[cur.first][cur.second];
                return;
            }
            board[nx][ny] = board[cur.first][cur.second] + 1;
            Q.push({ nx,ny });
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    int R, C, S, K;
    cin >> R >> C >> S >> K;
    bfs(R, C, S, K);
    return 0;
}