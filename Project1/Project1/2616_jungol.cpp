#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    cin.tie(0); ios_base::sync_with_stdio(0);

    int N, M;
    //N 개수 M 바이트
    cin >> N >> M;
    //m byte, cost
    vector<pair<int, int>> v;
    int temp;
    int sumcost = 0;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        v.push_back({ temp,0 });
    }
    for (int i = 0; i < N; i++) {
        cin >> temp;
        sumcost += temp;
        v[i].second = temp;
    }

    //dp[비용] = {바이트}
    int dp[10000] = { 0 };
    for (auto i : v) {
        for (int j = sumcost; j >= i.second; j--) {
            dp[j] = max(dp[j - i.second] + i.first, dp[j]);
        }
    }
    for (int i = 0; i <= 10000; i++) {
        if (dp[i] >= M) {
            cout << i;
            return 0;
        }
    }

    return 0;
}