#include <iostream>
#include <vector>
#include <algorithm>
#define x first
#define y second
using namespace std;

int ele[101];
int ans[101];
vector<pair<int, pair<int, int>>> v;
void recur(int tg, int cnt) {
    if (ele[tg] == 0) {
        ans[tg] += cnt;
        return;
    }
    for (const auto& i : v) {
        if (i.x != tg) continue;
        recur(i.y.x, i.y.y * cnt);
    }
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int t, n, cnt;
        cin >> t >> n >> cnt;
        v.push_back({ t,{n,cnt} });
        ele[t] = 1;
    }
    recur(N, 1);
    for (int i = 1; i <= N; i++) {
        if (ans[i] == 0) continue;
        cout << i << " " << ans[i] << "\n";
    }
    return 0;
}