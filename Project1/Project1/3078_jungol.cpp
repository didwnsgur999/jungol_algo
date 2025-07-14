#include <queue>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#define x first
#define y second
using namespace std;

struct hash_pair {
    size_t operator()(const pair<int, int>& p) const {
        return hash<long long>()(((long long)p.x << 32) | p.y);
    }
};

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    unordered_set<pair<int, int>, hash_pair> vis;

    queue<pair<pair<int, int>, int>> q;
    q.push({ {0,0},0 });
    vis.insert({ 0,0 });
    while (!q.empty()) {
        auto cur = q.front();
        int ca = cur.x.x;
        int cb = cur.x.y;
        int cnt = cur.y;
        q.pop();
        if (ca == c && cb == d) {
            cout << cnt;
            return 0;
        }

        for (int i = 0; i < 6; i++) {
            int na = ca, nb = cb;
            if (i == 0)
                na = a;
            else if (i == 1)
                nb = b;
            else if (i == 2)
                na = 0;
            else if (i == 3)
                nb = 0;
            else if (i == 4) {
                //ca를 cb에 붓고 남는거 남긴다
                if (cb + ca <= b) {
                    na = 0;
                    nb = ca + cb;
                }
                else {
                    na = ca + cb - b;
                    nb = b;
                }
            }
            else if (i == 5) {
                //cb를 ca에 붓고 남는거 남긴다
                if (cb + ca <= a) {
                    na = ca + cb;
                    nb = 0;
                }
                else {
                    na = a;
                    nb = ca + cb - a;
                }
            }
            if (vis.count({ na,nb })) continue;
            vis.insert({ na,nb });
            q.push({ {na,nb},cnt + 1 });
        }
    }
    cout << -1;

    return 0;
}