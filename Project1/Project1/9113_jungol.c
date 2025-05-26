#include <stdio.h>
#include <string.h>

int main(void) {
    char str[101] = "우리나라 대한민국!";
    int len = strlen(str);
    printf("%s\n", str);
    printf("위 문자열의 길이는 %d입니다.", len);
}