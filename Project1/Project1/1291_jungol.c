#include <stdio.h>

int main(void) {
    int s, e;
    scanf("%d %d", &s, &e);
    while (s < 2 || s>9 || e < 2 || e>9) {
        printf("INPUT ERROR!\n");
        scanf("%d %d", &s, &e);
    }
    if (s < e) {
        for (int i = 1; i <= 9; i++) {
            for (int j = s; j <= e; j++) {
                printf("%d * %d =%3d", j, i, i * j);
                if (j != e) printf("   ");
                else printf("\n");
            }
        }
    }
    else {
        for (int i = 1; i <= 9; i++) {
            for (int j = s; j >= e; j--) {
                printf("%d * %d =%3d", j, i, i * j);
                if (j != e) printf("   ");
                else printf("\n");
            }
        }
    }

    return 0;
}