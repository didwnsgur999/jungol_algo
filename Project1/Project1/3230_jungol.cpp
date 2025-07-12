#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define x first
#define y second
using namespace std;

vector<vector<pair<int, int>>> tun;
vector<int> vis;
int ans = INT_MAX;

void bfs(int st, int ed) {
    queue<pair<int, int>> q;
    q.push({ st,0 });
    //시작점은 다시 갈일없으니까 0 처리
    fill(vis.begin(), vis.end(), INT_MAX);
    vis[st] = 0;
    while (!q.empty()) {
        auto cura = q.front();
        int cur = cura.x;
        int curml = cura.y;
        q.pop();
        for (const auto& n : tun[cur]) {
            int nr = n.x;
            int nl = n.y;
            if (vis[nr] < nl + vis[cur]) continue;
            vis[nr] = nl + vis[cur];
            if (nr == ed) {
                ans = vis[nr] - (curml < nl ? nl : curml);
            }
            else {
                q.push({ nr,curml < nl ? nl : curml });
            }
        }
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int N, RA, RB;
    //1~N까지 
    cin >> N >> RA >> RB;
    tun.resize(N + 1);
    vis.resize(N + 1);
    int ed1, ed2, len;
    for (int i = 0; i < N - 1; i++) {
        cin >> ed1 >> ed2 >> len;
        tun[ed1].push_back({ ed2,len });
        tun[ed2].push_back({ ed1,len });
    }
    bfs(RA, RB);
    if (RA == RB)
        cout << 0;
    else
        cout << ans;

    return 0;
}