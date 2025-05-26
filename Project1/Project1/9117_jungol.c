#include <stdio.h>
#include <string.h>

int main(void) {
    char str[50];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len + i + 1; j++) {
            printf("%c", str[j % len]);
        }
        printf("\n");
    }
}