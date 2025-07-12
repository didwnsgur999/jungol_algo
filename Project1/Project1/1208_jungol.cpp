#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

#define x first
#define y second
#define MAX 52
#define MAXINT 0x3f3f3f3f

//A-Z, a-z
vector<vector<int>> node;

int dijkstra(int st, int ed) {
    vector<int> dist(MAX, MAXINT);
    vector<int> vis(MAX);
    //cost, next
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> path;
    path.push({ 0,st });
    dist[st] = 0;

    while (!path.empty()) {
        auto [cost, cx] = path.top();
        path.pop();
        if (cx == ed) {
            return cost;
        }
        for (int i = 0; i < MAX; i++) {
            if (node[cx][i] == MAXINT || i == cx) continue;
            if (dist[i] > node[cx][i] + cost) {
                dist[i] = node[cx][i] + cost;
                path.push({ node[cx][i] + cost,i });
            }
        }
    }
    return dist[ed];
}

int chartoidx(char t) {
    if (t - 'A' >= 0 && t - 'A' <= 25)
        return t - 'A';
    return t - 'a' + 26;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int P;
    cin >> P;
    char ed1, ed2;
    int len;
    node.resize(MAX);
    for (int i = 0; i < MAX; i++) {
        node[i].resize(MAX, MAXINT);
    }
    for (int i = 0; i < P; i++) {
        cin >> ed1 >> ed2 >> len;
        int e1 = chartoidx(ed1);
        int e2 = chartoidx(ed2);
        //두 목장은 한 개 이상의 길로 연결되어 있을 수도 있으며 -> 이거 왜 못봤냐..
        node[e1][e2] = min(node[e1][e2], len);
        node[e2][e1] = min(node[e2][e1], len);
    }
    int ans = MAXINT;
    char k = 'A';
    for (int i = 0; i <= 'Y' - 'A'; i++) {
        int cnt = dijkstra(i, 'Z' - 'A');
        if (ans > cnt) {
            ans = cnt;
            k = (char)i + 'A';
        }
    }
    cout << k << " " << ans;

    return 0;
}