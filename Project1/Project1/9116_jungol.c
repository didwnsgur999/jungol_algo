#include <stdio.h>
#include <string.h>
int main(void) {
    char str[101];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ')
            str[i] = '\n';
        printf("%c", str[i]);
    }
}