#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N, W;
    cin >> N;
    int dp[64001] = { 0 };
    vector<int> siz(N);
    for (int i = 0; i < N; i++) {
        cin >> siz[i];
    }
    cin >> W;
    fill(dp + 1, dp + W + 1, 99999);
    for (int i = 1; i <= W; i++) {
        for (const auto& j : siz) {
            if (i - j < 0) continue;
            dp[i] = min(dp[i], dp[i - j] + 1);
        }
    }
    if (dp[W] >= 99999)
        cout << "impossible";
    else
        cout << dp[W];

    return 0;
}