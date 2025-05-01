#include <stdio.h>
#include <string.h>
#define min(a,b) ((a)<(b)?(a):(b))
#define max(a,b) ((a)>(b)?(a):(b))
int main(void) {
    int N;
    scanf("%d", &N);
    getchar();
    char col[500001];
    int blue = 0;
    int red = 0;
    scanf("%s", col);
    char start = col[0], end = col[N - 1];
    int st = 0, ed = 0, idx = 0;
    while (start == col[idx]) {
        st++;idx++;
    }
    idx = N - 1;
    while (end == col[idx]) {
        ed++;idx--;
    }
    for (int i = 0; i < N; i++) {
        if (col[i] == 'B') blue++;
        else red++;
    }
    if (col[0] == col[N - 1]) {
        //color반대쪽이면 개수
        //color같은쪽이면 개수-max(st,ed)
        if (col[0] == 'R')
            printf("%d", min(blue, red - max(st, ed)));
        else
            printf("%d", min(blue - max(st, ed), red));
    }
    else {
        //red-st랑 blue-ed비교.
        if (col[0] == 'R')
            printf("%d", min(red - st, blue - ed));
        else
            printf("%d", min(blue - st, red - ed));
    }
}