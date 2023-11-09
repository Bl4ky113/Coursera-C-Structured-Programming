
#include <stdio.h>

enum Day { mon, tue, wed, thu, fri, sat, sun };

int main (void) {
	enum Day week_day = mon;

	printf("%d\n", week_day);

	week_day = 12; // Casting to Int (enum Day -> Int)

	printf("%d\n", week_day);

	return 0;
}
