#include <stdio.h>
#include <stdlib.h>
int arr[14];
int sel[6];
int compare(const void* a, const void* b) {
    return (int*)a > (int*)b;
}
void brute(int depth, int K, int st) {
    if (depth == 6) {
        for (int i = 0; i < 6; i++) {
            printf("%d ", arr[sel[i]]);
        }
        printf("\n");
        return;
    }
    for (int i = st; i < K; i++) {
        sel[depth] = i;
        brute(depth + 1, K, i + 1);
    }
}

int main(void) {
    int K;
    int lot = 49;
    scanf("%d", &K);
    for (int i = 0; i < K; i++) {
        scanf("%d", &arr[i]);
    }
    qsort(arr, K, sizeof(int), compare);
    brute(0, K, 0);
}