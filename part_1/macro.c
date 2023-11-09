
#include <stdio.h>

#define CONSTANT 123
#define MACRO printf("%d", CONSTANT + 321)

int main (void) {
	printf("%d\n", CONSTANT);
	MACRO;
	return 0;
}
