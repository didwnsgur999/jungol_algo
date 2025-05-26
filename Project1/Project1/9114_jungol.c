#include <stdio.h>
#include <string.h>

int main(void) {
    char c;
    while (1) {
        scanf(" %c", &c);
        if (c >= 'a' && c <= 'z') {
            printf("소문자입니다.\n");
        }
        else if (c >= 'A' && c <= 'Z') {
            printf("대문자입니다.\n");
        }
        else if (c >= '0' && c <= '9') {
            printf("숫자문자입니다.\n");
        }
        else
            break;
    }
    printf("영문, 숫자 이외의 문자입니다.");
}