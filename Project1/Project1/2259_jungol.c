#include <stdio.h>

int main(void) {
    //0 = dir, 1 = len;
    int K;
    scanf("%d", &K);
    int arr[6][2];
    int dir, len;
    int mx = 0, my = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        if (arr[i][0] == 1 || arr[i][0] == 2) {
            mx = (mx > arr[i][1]) ? mx : arr[i][1];
        }
        else my = (my > arr[i][1]) ? my : arr[i][1];
    }
    int sum = 0;
    for (int i = 0; i < 6; i++) {
        sum += arr[i][1] * arr[(i + 1) % 6][1];
    }
    sum -= 2 * mx * my;
    printf("%d\n", sum * K);
}