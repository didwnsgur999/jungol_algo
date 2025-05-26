#include <stdio.h>
#include <ctype.h>
#include <string.h>
int main(void) {
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i]))
            printf("%c", toupper(str[i]));
    }
}