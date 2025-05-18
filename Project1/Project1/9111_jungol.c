#include <stdio.h>

int main(void) {
    char c[16] = "jungol olympiad";
    int temp;
    for (int i = 0; i < 5; i++) {
        scanf("%d", &temp);
        printf("%c", c[temp]);
    }
}