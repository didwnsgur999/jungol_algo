//dijkstra 거의 첫 내가 푼 문제
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#define x first
#define y second
using namespace std;

int N, M;
vector<vector<int>> node;
vector<int> dist;
vector<int> path;

void dijkstra(int st, int ed) {
    //priority_queue->최대 queue-> -값 넣어서 최소 queue로 변경
    priority_queue<pair<int, int>> time;
    fill(dist.begin(), dist.end(), INT_MAX);
    //시작점 =1
    time.push({ 0,st });
    //st = 1 시작
    while (!time.empty()) {
        //현 시간, 현 위치
        int ct = -time.top().x;
        int cl = time.top().y;
        //path 저장, vis처리완료
        time.pop();
        //목적지 도착시 처리
        if (cl == ed) {
            cout << ct << "\n";
            vector<int> result;
            for (int v = ed; v != st; v = path[v]) {
                result.push_back(v);
            }
            result.push_back(st);
            reverse(result.begin(), result.end());
            for (const auto& i : result) {
                cout << i << " ";
            }
            return;
        }
        //cl = 1일때 갈수 있는 모든 경우의수 넣기.
        for (int i = 1; i <= N; i++) {
            int nt = ct + node[cl][i];
            if (nt < dist[i]) {
                dist[i] = nt;
                path[i] = cl;
                time.push({ -nt,i });
            }
        }
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    cin >> N >> M;
    node.resize(N + 1);
    for (int i = 0; i < N + 1; i++) {
        node[i].resize(N + 1);
    }
    dist.resize(N + 1);
    path.resize(N + 1);
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> node[i][j];
        }
    }
    dijkstra(1, M);

    return 0;
}