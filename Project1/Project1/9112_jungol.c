#include <stdio.h>
#include <string.h>
int main(void) {
    char c[80];
    scanf("%s", &c);
    int len = strlen(c);
    printf("�Է¹��� ���ڿ��� ���̴� %d�Դϴ�.\n", len);
    for (int i = len - 1; i >= 0; i--)
        printf("%c", c[i]);
}