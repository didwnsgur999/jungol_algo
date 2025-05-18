#include <stdio.h>

int main(void) {
    int c;
    while (1) {
        scanf(" %d", &c);
        printf("ASCII code =? ");
        if (c < 33 || c > 127) break;
        printf("%c\n", c);
    }
}