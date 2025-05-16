#include <stdio.h>
#include <string.h>

int main(void) {
    char str[102];
    char memo[500][100] = { 0 };
    int idx = -1;
    while (1) {
        fgets(str, sizeof(str), stdin);
        //strlen->5
        int len = strlen(str);
        str[len] = '\0';
        if (str == "END") {
            break;
        }

        char temp[101] = { 0, };
        for (int i = 0; i < len; i++) {
            int t_idx = 0;
            if (str[i] == ' ') {
                int flag = 0;
                for (int i = 0; i < idx + 1;i++) {
                    if (strcmp(memo[i], temp) == 0) {
                        flag = 1;
                        break;
                    }
                }
                if (!flag) {
                    strcpy(memo[++idx], temp);
                    //temp 초기화.
                }
                t_idx = 0;
            }
            else {
                temp[t_idx++] = str[i];
            }
        }
        for (int i = 0; i < idx + 1; i++) {
            printf("%s ", memo[i]);
        }
        printf("\n");
    }
}