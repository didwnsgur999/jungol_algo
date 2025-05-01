#include <stdio.h>

void hanoi(int n, int st, int ed, int mid) {
    if (n == 0) {
        return;
    }
    hanoi(n - 1, st, mid, ed);
    printf("%d : %d -> %d\n", n, st, ed);
    hanoi(n - 1, mid, ed, st);
}

int main(void) {
    int N;
    scanf("%d", &N);
    hanoi(N, 1, 3, 2);
}