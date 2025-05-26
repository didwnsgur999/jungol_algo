#include <stdio.h>
#include <string.h>

int main(void) {
    char c;
    while (1) {
        scanf(" %c", &c);
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            printf("%c\n", c);
        else if (c >= '0' && c <= '9')
            printf("%d\n", c);
        else
            break;
    }
}