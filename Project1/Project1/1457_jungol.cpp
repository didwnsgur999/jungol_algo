#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int board[101][101];
int vis[101][101];
vector<int> Area;
int num;
int temp;
void dfs(int x, int y) {
    vis[x][y] = 1;
    temp++;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= M || ny < 0 || ny >= N || board[nx][ny] == 1) continue;
        if (vis[nx][ny] == 1) continue;
        temp++;
        dfs(nx, ny);
    }
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> M >> N >> K;
    for (int i = 0; i < K; i++) {
        int ldx, ldy, rux, ruy;
        cin >> ldx >> ldy >> rux >> ruy;
        //02 44
        for (int i = ldx; i < rux; i++) {
            for (int j = ldy; j < ruy; j++) {
                board[j][i] = 1;
            }
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == 0 && vis[i][j] == 0) {
                num++;
                temp = 0;
                dfs(i, j);
                Area.push_back(temp);
            }
        }
    }
    sort(Area.begin(), Area.end());
    cout << num << "\n";
    for (auto i : Area) cout << i << " ";
    cout << "\n";

}
