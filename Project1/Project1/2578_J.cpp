#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define x first
#define y second

using namespace std;

bool isHori(int sx, int ex) {
    if (sx == ex)
        return 1;
    else
        return 0;
}

bool overlap(int sx, int ex, int sx2, int ex2) {
    if (sx > ex) swap(sx, ex);
    if (sx2 > ex2) swap(sx2, ex2);
    return max(sx, sx2) <= min(ex, ex2);
}

bool between(int sx, int ex, int tx) {
    if (sx > ex) swap(sx, ex);
    if (tx >= sx && tx <= ex)
        return 1;
    else
        return 0;
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int m, n, k;
    cin >> m >> n >> k;

    vector<pair<pair<int, int>, pair<int, int>>> bus(k + 1);
    //초기 bus 세팅
    int b, x1, y1, x2, y2, sx, sy, ex, ey;
    for (int i = 0; i < k; i++) {
        cin >> b >> x1 >> y1 >> x2 >> y2;
        bus[b] = { {x1,y1},{x2,y2} };
    }
    cin >> sx >> sy >> ex >> ey;
    //cnt, 현재 위치
    queue<pair<int, int>> q;
    vector<int> des;
    vector<int> use(k + 1);
    //bus st, ed 넣기
    for (int i = 1; i < k + 1; i++) {
        //시작 조건에 있는 버스 = horizontal하고 sx=bus.x.x
        if (isHori(bus[i].x.x, bus[i].y.x) && sx == bus[i].x.x) {
            if (between(bus[i].x.y, bus[i].y.y, sy)) {
                q.push({ i,1 });
                use[i] = 1;
            }
        }
        if ((!isHori(bus[i].x.x, bus[i].y.x)) && sy == bus[i].x.y) {
            if (between(bus[i].x.x, bus[i].y.x, sx)) {
                q.push({ i,1 });
                use[i] = 1;
            }
        }
        //종료조건으로 가는 버스 
        if (isHori(bus[i].x.x, bus[i].y.x) && ex == bus[i].x.x) {
            if (between(bus[i].x.y, bus[i].y.y, ey)) {
                des.push_back(i);
            }
        }
        if ((!isHori(bus[i].x.x, bus[i].y.x)) && ey == bus[i].x.y) {
            if (between(bus[i].x.x, bus[i].y.x, ex)) {
                des.push_back(i);
            }
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (auto& i : des) {
            if (i == cur.x) {
                cout << cur.y;
                return 0;
            }
        }
        int cursx = bus[cur.x].x.x;
        int cursy = bus[cur.x].x.y;
        int curex = bus[cur.x].y.x;
        int curey = bus[cur.x].y.y;
        int curt = isHori(cursx, curex);
        //bus와 교차되는 bus 탐색
        for (int i = 1; i <= k; i++) {
            if (use[i]) continue;
            int nxtsx = bus[i].x.x;
            int nxtsy = bus[i].x.y;
            int nxtex = bus[i].y.x;
            int nxtey = bus[i].y.y;
            int nxtt = isHori(nxtsx, nxtex);
            //여기서 cur bus랑 nxtbus랑 접점이 있는지 구하고 있다면 queue에 넣고 cnt+1;
            //수직, 수평, 직교
            if (nxtt == curt) { //수직, 수평
                if (nxtt) {
                    //x좌표가 같음
                    if (nxtsx == cursx && overlap(cursy, curey, nxtsy, nxtey)) {
                        use[i] = 1;
                        q.push({ i,cur.y + 1 });
                    }
                }
                else {
                    //y좌표가 같음.
                    if (nxtsy == cursy && overlap(cursx, curex, nxtsx, nxtex)) {
                        use[i] = 1;
                        q.push({ i,cur.y + 1 });
                    }
                }
            }
            else {   //직교하는지 확인
                if (nxtt) {
                    //nxt가 x좌표 같음 cur y좌표 같음
                    if (between(cursx, curex, nxtsx) && between(nxtsy, nxtey, cursy)) {
                        use[i] = 1;
                        q.push({ i,cur.y + 1 });
                    }
                }
                else {
                    //nxt가 y좌표 같음 cur x좌표 같음
                    if (between(cursy, curey, nxtsy) && between(nxtsx, nxtex, cursx)) {
                        use[i] = 1;
                        q.push({ i,cur.y + 1 });
                    }
                }
            }
        }
    }

    return 0;
}