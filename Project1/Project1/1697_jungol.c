#include <stdio.h>

int arr[101];
int front = 0;
int rear = 0;
void push(int a) {
    arr[front++] = a;
}
void pop() {
    if (front != rear)
        printf("%d\n", arr[rear++]);
    else
        printf("empty\n");
}
void count() {
    printf("%d\n", front - rear);
}
int main(void) {
    int N;
    char ops;

    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf(" %c", &ops);
        if (ops == 'i') {
            int temp;
            scanf("%d", &temp);
            push(temp);
        }
        else if (ops == 'o') {
            pop();
        }
        else if (ops == 'c') {
            count();
        }
    }
}