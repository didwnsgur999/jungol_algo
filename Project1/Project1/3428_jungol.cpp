#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> up[100001];
vector<int> down[100001];
vector<int> vis;
int N, M, X;
int u, d;
void dfs_up(int n) {
    for (auto& i : up[n]) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        u++;
        dfs_up(i);
    }
}
void dfs_down(int n) {
    for (auto& i : down[n]) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        d++;
        dfs_down(i);
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    //N = 학생의 범위, M = 비교 횟수, X = target
    cin >> N >> M >> X;
    vis.resize(N + 1);
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        up[b].push_back(a);
        down[a].push_back(b);
    }
    dfs_up(X);
    dfs_down(X);
    cout << u + 1 << " " << N - d;

    return 0;
}