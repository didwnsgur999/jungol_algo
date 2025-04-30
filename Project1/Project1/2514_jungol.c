#include <stdio.h>
#include <string.h>

int main(void) {
    char str[10001];
    scanf("%s", str);
    int len = strlen(str);
    int cnt1 = 0, cnt2 = 0;
    for (int i = len - 1; i >= 2; i--) {
        if (str[i] == 'I') {
            if (str[i - 1] == 'O') {
                if (str[i - 2] == 'K') {
                    cnt1++;
                    i -= 1;
                }
                else if (str[i - 2] == 'I') {
                    cnt2++;
                    i -= 1;
                }
            }
        }
    }
    printf("%d\n%d", cnt1, cnt2);
    return 0;
}