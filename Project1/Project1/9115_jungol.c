#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main(void) {
    char str[101];
    scanf("%s", str);
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isupper(str[i]))
            printf("%c", tolower(str[i]));
        else if (islower(str[i]))
            printf("%c", toupper(str[i]));
        else
            printf("%c", str[i]);
    }
}