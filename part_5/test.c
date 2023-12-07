
#include <stdio.h>
#include <stdlib.h>

typedef enum choices {left, left_center = 2, right_center, right = 5} choices;

int main (void) {
	choices foo = right_center;
	printf("%d", foo);
	return 0;
}
