#include <stdio.h>
int main(void) {
	char x, y;
	x = -128;
	y = -x;
	if (x != y) printf("4");
}