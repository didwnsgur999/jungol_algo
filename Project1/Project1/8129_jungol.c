#include <stdio.h>

int tmp[11];
int cnt = 1;
int flag = 0;

void check(int depth, int st, int N, int K, int* ans) {
    if (depth == K) {
        int dif = 0;
        for (int i = 0; i < K; i++) {
            if (tmp[i] != ans[i]) {
                dif = 1;
                break;
            }
        }
        if (dif == 1) cnt++;
        else {
            flag = 1;
            printf("%d", cnt);
        }
        return;
    }
    for (int i = st; i <= N; i++) {
        tmp[depth] = i;
        check(depth + 1, i + 1, N, K, ans);
    }
}

int main(void) {
    int N;
    int K;
    scanf("%d %d", &N, &K);
    int arr[11] = { 0, };
    for (int i = 0; i < K; i++)
        scanf("%d", &arr[i]);
    check(0, 1, N, K, arr);
    if (!flag) printf("None");
}