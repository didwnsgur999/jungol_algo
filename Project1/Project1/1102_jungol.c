#include <stdio.h>

int main(void) {
    int n;
    int arr[101] = { 0 };
    scanf("%d", &n);
    char ops;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        getchar();
        scanf("%c", &ops);
        if (ops == 'i') {
            getchar();
            scanf("%d", &arr[idx++]);
        }
        else if (ops == 'o') {
            if (idx == 0) {
                printf("empty\n");
            }
            else {
                printf("%d\n", arr[--idx]);
            }
        }
        else if (ops == 'c') {
            printf("%d\n", idx);
        }
    }
}