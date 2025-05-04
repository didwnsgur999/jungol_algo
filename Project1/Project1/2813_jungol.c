#include <stdio.h>

int main(void) {
    //소수면 1 소수아니면 0
    int arr[3000001] = { 0 };
    int M, N;
    scanf("%d %d", &M, &N);
    for (int i = 2; i <= N; i++)
        arr[i] = 1;
    int cnt = 0;
    for (int i = 2; i * i <= N; i++) {
        if (arr[i] == 0) continue;
        for (int j = i * i; j <= N; j += i) {
            arr[j] = 0;
        }
    }
    for (int i = M; i <= N; i++) {
        //소수면 카운트
        if (arr[i]) cnt++;
    }
    printf("%d", cnt);
    return 0;
}