#include <stdio.h>

int main(void) {
    char c;
    while (1) {
        c = getchar();
        if (c == '\n') break;
        printf("%c", c);
    }
}