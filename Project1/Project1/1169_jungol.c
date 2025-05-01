#include <stdio.h>
int arr[5];
int vis[7];

void brute(int depth, int n) {
    if (depth == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i < 7; i++) {
        arr[depth] = i;
        brute(depth + 1, n);
    }
}
void brute_C(int depth, int n, int st) {
    if (depth == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = st; i < 7; i++) {
        arr[depth] = i;
        brute_C(depth + 1, n, i);
    }
}
void brute_noR(int depth, int n) {
    if (depth == n) {
        for (int i = 0; i < n; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    for (int i = 1; i < 7; i++) {
        if (vis[i] == 1) continue;
        vis[i] = 1;
        arr[depth] = i;
        brute_noR(depth + 1, n);
        vis[i] = 0;
    }
}

int main(void) {
    int N, M;
    scanf("%d %d", &N, &M);
    if (M == 1) {
        brute(0, N);
    }
    else if (M == 2) {
        brute_C(0, N, 1);
    }
    else {
        brute_noR(0, N);
    }
}