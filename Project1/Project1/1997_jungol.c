#include <stdio.h>

int main(void) {
    int D, K;
    int dp[31][2] = { 0 };
    scanf("%d %d", &D, &K);
    dp[1][0] = 1;
    dp[2][1] = 1;
    for (int i = 3; i <= D; i++) {
        dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
        dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
    }
    int temp = K;
    int A = 1;
    while (1) {
        if ((temp - A * dp[D][0]) % dp[D][1] == 0) {
            printf("%d\n%d", A, (temp - A * dp[D][0]) / dp[D][1]);
            return 0;
        }
        A++;
    }
    return 0;
}