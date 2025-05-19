#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int N;
    int arr[101][101] = { 0, };
    scanf("%d", &N);
    int idx = N / 2, jdx = 0, cnt;
    for (cnt = 1; cnt <= N * N; cnt++) {
        arr[jdx--][idx--] = cnt;
        if (jdx < 0) jdx = N - 1;
        if (idx < 0) idx = N - 1;
        if (arr[jdx][idx] != 0) {
            if (jdx == N - 1) {
                jdx = 1;
            }
            else {
                jdx += 2;
            }
            if (idx == N - 1) {
                idx = 0;
            }
            else {
                idx++;
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}