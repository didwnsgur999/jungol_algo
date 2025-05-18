#include <stdio.h>
#include <string.h>

int main(void) {
    char str[14] = "Hong Gil Dong";
    for (int i = 3; i <= 6; i++)
        printf("%c", str[i]);
}