#include <stdio.h>
#include <string.h>

int main(void) {
    char dec[30];
    char str[100];
    int num;
    //fgets 사용법 잊지말기.
    fgets(dec, sizeof(dec), stdin);
    fgets(str, sizeof(str), stdin);
    //printf("%s",dec);
    //fgets에서 \n이 받아지기 때문에 -1해줘야한다.
    int len = strlen(str) - 1;
    for (int i = 0; i < len; i++) {
        if (str[i] == ' ') {
            continue;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = dec[str[i] - 'A'] - ('a' - 'A');
        }
        else {
            str[i] = dec[str[i] - 'a'];
        }
    }
    printf("%s", str);
    return 0;
}