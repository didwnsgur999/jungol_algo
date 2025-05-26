#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
int main(void) {
    bool flush = true, straight = true;
    bool four = false, trips = false;
    int setmax = 0;
    int duce[2] = { 0, };
    char color, last;
    int num;
    int arr[5] = { 0, };
    int nums[10] = { 0, };
    for (int i = 0; i < 5; i++) {
        scanf(" %c %d", &color, &num);
        if (i == 0)
            last = color;
        else if (color != last)
            flush = false;
        arr[i] = num;
        nums[num]++;
        last = color;
    }
    for (int i = 1; i <= 9; i++) {
        if (nums[i] == 4) {
            four = true;
            setmax = i;
            break;
        }
        else if (nums[i] == 3) {
            trips = true;
            setmax = i;
        }
        else if (nums[i] == 2) {
            if (duce[0] != 0) {
                duce[1] = i;
            }
            else {
                duce[0] = i;
            }
        }
    }
    qsort(arr, 5, sizeof(int), compare);
    for (int i = 0; i < 4; i++) {
        if (arr[i + 1] - arr[i] != 1) {
            straight = false;
            break;
        }
    }
    if (flush && straight)
        printf("%d", arr[4] + 900);
    else if (four)
        printf("%d", setmax + 800);
    else if (trips && duce[0])
        printf("%d", setmax * 10 + duce[0] + 700);
    else if (flush)
        printf("%d", arr[4] + 600);
    else if (straight)
        printf("%d", arr[4] + 500);
    else if (trips)
        printf("%d", setmax + 400);
    else if (duce[1]) {
        printf("%d", 300 + (duce[1] < duce[0] ? duce[0] * 10 + duce[1] : duce[1] * 10 + duce[0]));
    }
    else if (duce[0])
        printf("%d", duce[0] + 200);
    else
        printf("%d", arr[4] + 100);
    return 0;
}