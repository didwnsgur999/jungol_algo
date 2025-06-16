#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> v[100001];
int N;
vector<int> vis;
int cnt;
int ans[100001];
void dfs(int cur) {
    if (cnt == N) {
        for (int i = 0; i < N; i++)
            cout << ans[i] << " ";
        return;
    }
    for (auto i : v[cur]) {
        if (vis[i] == 0) {
            vis[i] = 1;
            ans[cnt++] = i;
            dfs(i);
        }
    }
}
int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int M;
    cin >> N >> M;
    vis.resize(N + 1);
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 1; i <= N; i++)
        sort(v[i].begin(), v[i].end());
    vis[1] = 1;
    ans[cnt++] = 1;
    dfs(1);
    return 0;
}