#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[12];
int idx = -1;
void push(char x) {
    stack[++idx] = x;
}
char pop() {
    return stack[idx--];
}
int recursive(char cur) {
    char a, b;
    a = pop();
    int inta, intb;
    if (a == '+' || a == '-' || a == '*' || a == '/') {
        inta = recursive(a);
    }
    else
        inta = a - '0';
    b = pop();
    if (b == '+' || b == '-' || b == '*' || b == '/') {
        intb = recursive(b);
    }
    else
        intb = b - '0';
    if (cur == '+')
        return intb + inta;
    else if (cur == '-')
        return intb - inta;
    else if (cur == '*')
        return intb * inta;
    else if (cur == '/')
        return intb / inta;
}
int main(void) {
    int M;
    int res = 0;
    scanf("%d", &M);
    for (int i = 0; i < M; i++) {
        char temp;
        scanf(" %c", &temp);
        push(temp);
    }
    char cur = pop();
    res = recursive(cur);
    printf("%d", res);
}