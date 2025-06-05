#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int blank;
int board[11][11];
int cross1[21];//x+y=고정
int cross2[21];//N+x-y 고정
int black_res;
int white_res;
int N;
vector<pair<int, int>> black;
vector<pair<int, int>> white;
void dfs(vector<pair<int, int>>& space, int idx, int cnt, int& res) {
    if (idx == space.size()) {
        if (res < cnt) {
            res = cnt;
        }
        return;
    }
    int x = space[idx].first;
    int y = space[idx].second;
    //비숍 놓기 cross 없고, board
    if (!(cross1[x + y] || cross2[N - 1 + x - y] || board[x][y] == 0)) {
        board[x][y] = 0;cross1[x + y] = 1;cross2[N - 1 + x - y] = 1;
        dfs(space, idx + 1, cnt + 1, res);
        board[x][y] = 1;cross1[x + y] = 0;cross2[N - 1 + x - y] = 0;
    }
    //비숍 안놓고 넘어가기.
    dfs(space, idx + 1, cnt, res);
}

int main(void) {
    cin.tie(0);ios_base::sync_with_stdio(0);
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) {
                if ((i + j) % 2) black.push_back({ i,j });
                else white.push_back({ i,j });
            }
        }
    }
    dfs(black, 0, 0, black_res);
    dfs(white, 0, 0, white_res);
    cout << black_res + white_res << endl;
}
