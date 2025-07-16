#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int T, N, M, B;
vector<tuple<int, int, int>> edge;

bool timework(int st) {
    //모든 distance를 초기화
    vector<int> dis(N + 1, 0x3f3f3f3f);
    dis[st] = 0;
    for (int i = 1; i <= N + 1; i++) {
        for (auto [st, ed, cost] : edge) {
            if (dis[st] != 0x3f3f3f3f && dis[ed] > cost + dis[st]) {
                dis[ed] = cost + dis[st];
            }
        }
    }
    for (auto [st, ed, cost] : edge) {
        if (dis[st] != 0x3f3f3f3f && dis[ed] > cost + dis[st]) {
            return 1;
        }
    }
    return 0;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    //testcase
    cin >> T;
    while (T--) {
        edge.clear();
        //N = 영역, M = 양방향경로, B = 단방향블랙홀
        cin >> N >> M >> B;
        int s, e, cnt;
        //양방향
        for (int i = 0; i < M; i++) {
            cin >> s >> e >> cnt;
            edge.push_back({ s,e,cnt });
            edge.push_back({ e,s,cnt });
        }
        //단뱡향
        for (int i = 0; i < B; i++) {
            cin >> s >> e >> cnt;
            edge.push_back({ s,e,-cnt });
        }
        //슈퍼노드
        for (int i = 1; i <= N; i++) {
            edge.push_back({ 0, i, 0 });
        }
        //시간여행 -> i->i가는데 과거값이 나오냐?
        if (timework(0))cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}