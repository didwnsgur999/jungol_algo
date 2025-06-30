#include <string>
#include <queue>
#include <algorithm>
#include <iostream>
#define x first
#define y second
using namespace std;

int board[51][51];
int visit[51][51];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
queue<pair<int, int>> jw;
queue<pair<int, int>> fire;
int jwcnt, firecnt;
int R, C;

// void print_(){
//     for(int i=0; i<R; i++){
//         for(int j=0; j<C; j++){
//             cout<<board[i][j];
//         }
//         cout<<"\n";
//     }
//     cout<<"\n";
// }

void bfs() {
    while (1) {
        for (int i = 0;i < jwcnt;i++) {
            auto cur = jw.front();
            jw.pop();
            if (board[cur.x][cur.y] == 1) continue;
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny>=C) continue;
                if (board[nx][ny] == 2 || board[nx][ny] == 1 || visit[nx][ny]) continue;
                    if (board[nx][ny] == 3) {
                        cout << visit[cur.x][cur.y];
                        return;
                    }
                visit[nx][ny] = visit[cur.x][cur.y] + 1;
                    jw.push({ nx,ny });
            }
        }
        jwcnt = jw.size();
            if (jwcnt == 0) {
                cout << "impossible";
                return;
            }
        for (int i = 0; i < firecnt; i++) {
            auto cur = fire.front();
            fire.pop();
            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                if (board[nx][ny] != 0) continue;
                board[nx][ny] = 1;
                fire.push({ nx,ny });
            }
        }
        firecnt = fire.size();
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    string temp;
    cin >> R >> C;
    int stx, sty, edx, edy;
    for (int i = 0; i < R; i++) {
        cin >> temp;
        for (int j = 0; j < C; j++) {
            if (temp[j] == 'D') {
                board[i][j] = 3;
                stx = i; sty = j;
            }
            else if (temp[j] == 'S') {
                jw.push({ i,j });
                visit[i][j] = 1;
            }
            else if (temp[j] == '*') {
                board[i][j] = 1;
                fire.push({ i,j });
            }
            else if (temp[j] == 'X') {
                board[i][j] = 2;
            }
        }
    }
    jwcnt = jw.size();
    firecnt = fire.size();
    bfs();
    return 0;
}