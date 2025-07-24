#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
vector<tuple<int, int, int, int, int>> food;
vector<int> tmp;
vector<int> ans;
int cost = 0x3f3f3f3f;
int N, mp, mf, ms, mv;
void dfs(int depth, int cp, int cf, int cs, int cv, int cc) {
    if (cp >= mp && cf >= mf && cs >= ms && cv >= mv) {
        if (cost > cc) {
            cost = cc;
            ans = tmp;
        }
        return;
    }
    if (depth == N) {
        return;
    }
    auto [p, f, s, v, c] = food[depth];
    tmp.push_back(depth + 1);
    dfs(depth + 1, cp + p, cf + f, cs + s, cv + v, cc + c);
    tmp.pop_back();
    dfs(depth + 1, cp, cf, cs, cv, cc);
}

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int p, f, s, v, c;
    cin >> N >> mp >> mf >> ms >> mv;
    for (int i = 0; i < N; i++) {
        cin >> p >> f >> s >> v >> c;
        food.push_back({ p,f,s,v,c });
    }
    dfs(0, 0, 0, 0, 0, 0);

    if (cost == 0x3f3f3f3f) {
        cout << -1;
    }
    else {
        cout << cost << "\n";
        for (const auto& i : ans) {
            cout << i << " ";
        }
    }
    return 0;
}