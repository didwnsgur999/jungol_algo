#include <stdio.h>

int main(void) {
    char c = '1';
    while (c != '0') {
        c = getchar();
        if (c == '\n' || c == '\r') continue;
        printf("%c -> %d\n", c, c);
    }
    return 0;
}