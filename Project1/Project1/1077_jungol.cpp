#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdint>
#define x first
#define y second
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int dp[10001] = { 0 };
    int N, W, ans = 0;
    cin >> N >> W;
    //weight,price
    vector<pair<int, int>> jew(N);
    for (int i = 0; i < N; i++) {
        cin >> jew[i].x >> jew[i].y;
    }
    for (int i = 1; i <= W; i++) {
        for (const auto& j : jew) {
            if (i < j.x) continue;
            dp[i] = max(dp[i], dp[i - j.x] + j.y);
        }
    }
    for (int i = 1; i <= W; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}