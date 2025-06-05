#include <iostream>
#include <vector>
#include <algorithm>
//벽장개수,열린 벽장 1,2
using namespace std;

int N, W1, W2, T;
vector<int> tar;
int board[20];
int ans = 999999;

void dfs(int depth, int cnt, int w1, int w2) {
    if (depth == T) {
        if (ans > cnt) ans = cnt;
        return;
    }
    int target = tar[depth];
    if (target == w1 || target == w2) {
        dfs(depth + 1, cnt, w1, w2);
    }
    else {
        if (cnt + abs(target - w1) < ans)
            dfs(depth + 1, cnt + abs(w1 - target), target, w2);
        if (cnt + abs(target - w2) < ans)
            dfs(depth + 1, cnt + abs(w2 - target), w1, target);
    }
}

int main(void) {
    cin >> N >> W1 >> W2 >> T;
    tar.resize(T - 1);
    for (int i = 0; i < T; i++) {
        cin >> tar[i];
    }
    dfs(0, 0, W1, W2);
    cout << ans;
}