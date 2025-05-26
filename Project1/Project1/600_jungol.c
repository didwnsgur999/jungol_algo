#include <string.h>
#include <stdio.h>

int main(void) {
    char str[101];
    fgets(str, sizeof(str), stdin);
    int len = strlen(str);
    int cnt = 1;
    for (int i = 0; i < len; i++)
        if (str[i] == ' ') cnt++;
    printf("%d", cnt);
}