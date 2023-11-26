
#include <stdio.h>
#include <stdlib.h>

int main (int argc,  char **arg) {
	FILE * output = stdout;

	printf("%x\n", output);

	printf("%d\n", argc);

	for (int i = 0; i < argc; i++) {
		printf("%s\t", arg[i]);
	}
	
	return 0;
}
