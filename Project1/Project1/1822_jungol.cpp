#include <iostream>
#include <algorithm>
using namespace std;

long long dp[1000001];

int main(void) {
    int a, b, d, N;
    cin >> a >> b >> d >> N;
    dp[0] = 1;
    for (int i = 1; i <= N; i++) {
        if (i < a) dp[i] = dp[i - 1] % 1000;
        else if (i < b) dp[i] = (dp[i - 1] + dp[i - a]) % 1000;
        else dp[i] = (dp[i - 1] + dp[i - a] - dp[i - b] + 1000) % 1000;
    }
    if (N - d >= 0)cout << (dp[N] - dp[N - d] + 1000) % 1000;
    else cout << dp[N] % 1000;
}