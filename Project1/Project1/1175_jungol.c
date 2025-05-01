#include <stdio.h>

int arr[8];

void dfs(int depth, int N, int M) {
    if (depth == N) {
        int sum = 0;
        for (int i = 0; i < N; i++)
            sum += arr[i];
        if (sum == M) {
            for (int i = 0;i < N; i++)
                printf("%d ", arr[i]);
            printf("\n");
        }
        return;
    }
    for (int i = 1; i < 7; i++) {
        arr[depth] = i;
        dfs(depth + 1, N, M);
    }
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    dfs(0, N, M);

    return 0;
}