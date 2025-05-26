#include <stdio.h>
#include <string.h>
int main(void) {
    char str1[41];
    char str2[41];
    scanf("%s %s", str1, str2);
    strcat(str1, str2);
    printf("%d", strlen(str1));
}