#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
queue<int> Q;
vector<int> vis;
int dx[2] = { -1,1 };
int N;
void bfs() {
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        for (int i = 0; i < 2; i++) {
            int nx = cur + dx[i];
            if (vis[nx] != 0 || nx <= 0 || nx > N) continue;
            vis[nx] = vis[cur] + 1;
            Q.push(nx);
        }
    }
}

int main(void) {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int M;
    cin >> N >> M;
    vis.resize(N + 1);
    int temp;
    for (int i = 0; i < M; i++) {
        cin >> temp;
        Q.push(temp);
        vis[temp] = 1;
    }
    bfs();
    for (int i = 1; i <= N; i++)
        cout << vis[i] - 1 << " ";

    return 0;
}