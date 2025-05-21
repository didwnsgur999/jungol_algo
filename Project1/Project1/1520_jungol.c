#include <stdio.h>
#define max(a,b) ((a)>(b)?(a):(b))
int main(void) {
    int N;
    int stair[301];
    scanf("%d", &N);
    int dp[301][2] = { 0, };
    for (int i = 1; i <= N; i++)
        scanf("%d", &stair[i]);
    dp[1][0] = stair[1];
    dp[2][0] = stair[2];
    dp[2][1] = stair[1] + stair[2];
    for (int i = 3; i <= N; i++) {
        dp[i][0] = max(dp[i - 2][0], dp[i - 2][1]) + stair[i];
        dp[i][1] = dp[i - 1][0] + stair[i];
    }
    printf("%d", max(dp[N][0], dp[N][1]));
}