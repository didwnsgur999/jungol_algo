#include <iostream>
using namespace std;

int dp[100001];

int main(void) {
    int N;
    dp[1] = dp[2] = 1;
    cin >> N;
    for (int i = 3; i <= N; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000007;
    }
    cout << dp[N];
    return 0;
}