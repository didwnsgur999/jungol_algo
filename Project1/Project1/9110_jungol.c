#include <stdio.h>
#include <string.h>

int main(void) {
    char c[BUFSIZ];
    fgets(c, sizeof(c), stdin);
    c[strlen(c)] = '\0';
    fputs(c, stdout);
}