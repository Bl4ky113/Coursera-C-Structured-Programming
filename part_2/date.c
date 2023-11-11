/* 
	Write enumerated types that supports dates. 
	Then add a function that produces a next day.
	Also write a function printdate(date) that prints a date legibly.
	The function can assume that February has 28 days and it most know how many days are in each month.
	Use a struct with two members; one is the month and the second  is the day of the month—an int (or short)
*/

#include <stdio.h>

// Enum of the Months
typedef enum Month { 
	Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec 
} Month;

// Names of the Months (access by index)
char *MONTHS_NAMES[12] = {
	"January", "February", "March", "April", "May", "June", 
	"July", "August", "September", "October", "November", "December"
};

// Days in each Month (access by index)
int MONTHS_DAYS[12] = {
	31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

// Struct Date; Store the month in enum and day in int
typedef struct Date {
	Month month;
	int day;
} Date;

/** next_day
 * @param {Date *} date: Date Reference;
 * @return {int} New day saved in the date reference
 **/
int next_day (Date *date) {
	date->day++;

	if (date->day > MONTHS_DAYS[date->month]) {
		date->day = 1;
		date->month++;
	}

	if (date->month > 11) {
		date->month = 0;
	}

	return date->day;
}

/**
 * print_date
 * @param {Date *} date: Date Reference;
 * @return {NULL}
 **/
void print_date (Date *date) {
	printf("%s\t%d\n", MONTHS_NAMES[date->month], date->day);
	return;
}

int main (void) {
	// Create a list of Dates 
	// for Simplicity
	Date dates[5] = {
		{Jan, 13},
		{Feb, 28},
		{Mar, 14},
		{Oct, 31},
		{Dec, 31}
	};

	// Print the date, then add a day to it, then print it again.
	for (int i = 0; i < 5; i++) {
		print_date(&dates[i]);
		next_day(&dates[i]);
		print_date(&dates[i]);
		printf("======\n");
	}

	return 0;
}
