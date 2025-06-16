#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int N, M, R, C, S, K;
int board[1001][1001];

int dx[8] = { 1,2,2,1,-1,-2,-2,-1 };
int dy[8] = { 2,1,-1,-2,-2,-1,1,2 };

void bfs() {
    queue<pair<int, int>> Q;
    board[R][C] = 1;
    Q.push({ R,C });
    int x, y;
    while (!Q.empty()) {
        tie(x, y) = Q.front();
        Q.pop();
        for (int i = 0; i < 8; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx <= 0 || nx > N || ny <= 0 || ny > M || board[nx][ny] != 0) continue;
            if (nx == S && ny == K) {
                cout << board[x][y];
                return;
            }
            board[nx][ny] = board[x][y] + 1;
            Q.push({ nx,ny });
        }
    }
    cout << -1;
    return;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M >> R >> C >> S >> K;
    bfs();
    return 0;
}