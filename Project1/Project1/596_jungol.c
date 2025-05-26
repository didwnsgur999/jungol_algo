#include <stdio.h>
#include <string.h>

int main(void) {
    char str[101];
    int num;
    scanf("%s %d", str, &num);
    int len = strlen(str);
    if (len < num) num = len;
    //4 3 2
    for (int i = len - 1; i > len - 1 - num; i--) {
        printf("%c", str[i]);
    }
}