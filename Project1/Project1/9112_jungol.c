#include <stdio.h>
#include <string.h>
int main(void) {
    char c[80];
    scanf("%s", &c);
    int len = strlen(c);
    printf("입력받은 문자열의 길이는 %d입니다.\n", len);
    for (int i = len - 1; i >= 0; i--)
        printf("%c", c[i]);
}