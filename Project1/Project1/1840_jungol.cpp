#include <iostream>
#include <vector>
#include <queue>
#define x first
#define y second

using namespace std;
//1~100사용
int board[102][102];
int vis[102][102];
int N, M;
int cheese;
//이동명령시
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

void bfs() {
    queue<pair<int, int>> Q;
    queue<pair<int, int>> CH;
    int time = 0;
    //1. 초기 치즈 확인
    while (cheese != 0) {
        for (int i = 0; i <= N; i++) {
            for (int j = 0; j <= M; j++) {
                vis[i][j] = 0;
            }
        }
        Q.push({ 0,0 });
        while (!Q.empty()) {
            int x, y;
            tie(x, y) = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx<0 || nx>N || ny<0 || ny>M) continue;
                if (vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                if (board[nx][ny] == 1) {
                    CH.push({ nx,ny });
                    board[nx][ny] = 2;
                    continue;
                }
                else if (board[nx][ny] == 0) {
                    Q.push({ nx,ny });
                }
            }
        }
        //2. 확인된 치즈 박살
        int cnt = CH.size();
        while (!CH.empty()) {
            int x, y;
            tie(x, y) = CH.front();
            CH.pop();
            board[x][y] = 0;
        }
        //3. 시간추가, 치즈개수 정리
        time++;
        if (cheese == cnt) {
            cout << time << "\n";
            cout << cheese;
        }
        cheese -= cnt;
    }
}
int main(void) {
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            //치즈 있는칸 =1
            cin >> board[i][j];
            if (board[i][j] == 1) cheese++;
        }
    }
    bfs();
    return 0;
}