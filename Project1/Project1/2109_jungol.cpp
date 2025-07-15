#include <vector>
#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;

int N, M, X;
vector<vector<pair<int, int>>> road;

int djikstra(int st, int ed) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> dist(N + 1, 0x3f3f3f3f);
    pq.push({ 0,st });
    dist[st] = 0;
    while (!pq.empty()) {
        auto [cnt, cx] = pq.top();
        pq.pop();
        if (cx == ed) {
            return cnt;
        }
        for (int i = 0; i < road[cx].size(); i++) {
            auto [nx, cost] = road[cx][i];
            if (dist[nx] > cnt + cost) {
                int ncnt = cnt + cost;
                dist[nx] = ncnt;
                pq.push({ ncnt,nx });
            }
        }
    }
    return -1;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    cin >> N >> M >> X;
    int st, ed, ti;
    road.resize(N + 1);
    for (int i = 0; i < M; i++) {
        cin >> st >> ed >> ti;
        road[st].push_back({ ed,ti });
    }
    int ans = 0;
    //cost,start
    for (int i = 1; i <= N; i++) {
        ans = max(ans, djikstra(i, X) + djikstra(X, i));
    }
    cout << ans;

    return 0;
}