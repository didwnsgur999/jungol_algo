#include <stdio.h>
int main(void) {
    int N, num = 1;
    int dp[1000003] = { 0, };
    dp[0] = 1; dp[1] = 1;
    for (int i = 2; i * i <= 1000000; i++) {
        if (dp[i]) continue;
        for (int j = 2 * i; j <= 1000000; j += i) {
            dp[j] = 1;
        }
    }
    scanf("%d", &N);
    while (N--) {
        int tar;
        scanf("%d", &tar);
        int flag = 0, i = 1;
        if (dp[tar] == 0) {
            printf("%d\n", tar);
        }
        else {
            while (1) {
                if (tar - i >= 2 && dp[tar - i] == 0) {
                    printf("%d ", tar - i);
                    flag = 1;
                }
                if (tar + i <= 1000000 && dp[tar + i] == 0) {
                    printf("%d ", tar + i);
                    flag = 1;
                }
                if (flag) {
                    printf("\n");
                    break;
                }
                i++;
            }
        }

    }
}