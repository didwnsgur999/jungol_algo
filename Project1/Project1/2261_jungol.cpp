#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    vector<string> code(N + 1, "");
    vector<int> vis(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> code[i];
    }
    int st, ed;
    cin >> st >> ed;
    vis[st] = -1;
    //queue에 넣기
    queue<pair<string, int>> q;
    q.push({ code[st],st });
    //q.empty할때까지 hamming경로 탐색
    while (!q.empty()) {
        //현재 cur랑 그 인덱스 확인
        auto [cur, idx] = q.front();
        q.pop();
        if (cur == code[ed]) {
            //경로 탐색
            vector<int> path;
            path.push_back(idx);
            while (vis[idx] != -1) {
                path.push_back(vis[idx]);
                idx = vis[idx];
            }
            for (int i = path.size() - 1;i >= 0; i--) {
                cout << path[i] << " ";
            }
            return 0;
        }
        for (int i = 1;i <= N; i++) {
            if (vis[i] != 0) continue;
            int cnt = 0;
            for (int j = 0; j < K; j++) {
                if (cur[j] != code[i][j]) {
                    cnt++;
                }
            }
            if (cnt == 1) {
                vis[i] = idx;
                q.push({ code[i],i });
            }
        }
    }

    cout << -1;

    return 0;
}