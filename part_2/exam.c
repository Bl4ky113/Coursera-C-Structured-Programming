
#include <stdio.h>

int main (void ) {
	struct point{
			double x;
			double y;
	} p1 = { 4, 4.0}, p2;
	printf("%f\n", p1.y);

	printf("\t-----\t\n");

	struct point* ptr = &p2;

	printf("%lf", ptr->y);

	return 0;
}
