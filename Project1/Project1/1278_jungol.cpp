#include <iostream>
#include <vector>
#include <algorithm>
#define w first
#define p second
using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N, W;
    int wi, pi;
    cin >> N >> W;
    vector<int> dp(W + 1);
    vector<pair<int, int>> jew(N);
    //종류별로 1개씩
    for (int i = 0; i < N; i++) {
        cin >> jew[i].w >> jew[i].p;
    }
    //무게가 큰것, 가치가 큰것 sort
    sort(jew.begin(), jew.end(), [](auto a, auto b) {
        if (a.w == b.w) {
            return a.p > b.p;
        }
        return a.w > b.w;
        });
    //무게가 큰것부터 넣어본다. 이때 무게상 뒤에서부터 넣는다.
    for (int i = 0; i < N; i++) {
        int wei = jew[i].w;
        int cos = jew[i].p;
        for (int j = W; j >= wei; j--) {
            dp[j] = max(dp[j], dp[j - wei] + cos);
        }
    }
    cout << dp[W];

    return 0;
}