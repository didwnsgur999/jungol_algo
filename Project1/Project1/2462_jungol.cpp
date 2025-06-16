#include <iostream>
#include <vector> 
#include <algorithm>
//auto에 참조형만 붙였는데 40ms가 단축되었음 -> 개이득
using namespace std;
//b[1] = 1보다 큰 것만 들어있음.
vector<int> b[501];
vector<int> s[501];
vector<int> vis;
int cnt;
void dfs_up(int n) {
    for (auto& i : b[n]) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        cnt++;
        dfs_up(i);
    }
}
void dfs_down(int n) {
    for (auto& i : s[n]) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        cnt++;
        dfs_down(i);
    }
}
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N, M, ans = 0;
    cin >> N >> M;
    vis.resize(N + 1);
    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        b[x].push_back(y);
        s[y].push_back(x);
    }
    for (int i = 1; i <= N; i++) {
        cnt = 0;
        fill(vis.begin(), vis.end(), 0);
        dfs_up(i);
        dfs_down(i);
        if (cnt == N - 1) ans++;
    }
    cout << ans;

    return 0;
}