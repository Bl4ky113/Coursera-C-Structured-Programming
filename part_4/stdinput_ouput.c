
#include <stdio.h>

int main (int argc, char **arg) {
	int first_read = 0;

	fscanf(stdin, "%d", &first_read);

	for (int i = 0; i < first_read; i++) {
		int input = 0;

		fscanf(stdin, "%d", &input);

		fprintf(stdout, "%d\t", input * input);
	}

	fprintf(stdout, "\n");

	return 0;	
}
