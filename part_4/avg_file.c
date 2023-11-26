/* 
	Program that:
		Reads a list of numbers, it's size defined as the first int to read. 
		Then calculate the average of the numbers, get the max and min of the numbers, 
		print it to screen and save the list and the results in a file, by default the 
		file should be 'answer-hw3'
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_BUFFER 128

char *output_file_name = "./answer_hw3";
char *input_file_name = "./input_file";

/**
	* handle the command line args passed to the program
	* you can see the args available in the main function.
	* @param{int} argc: number of args passed
	* @param{char **} argv: vector of args' strings
	* @retrun{void}
	**/
void handle_command_line_args (int argc, char *argv[]) {
	for (int i = 0; i < argc; i++) {
		if ((strcmp("-o", argv[i]) == 0) || (strcmp("--output", argv[i]) == 0)) {
			// Set the output file name
			assert(i + 1 < argc); // Check if there's another arg available

			output_file_name = argv[++i];
		} else if ((strcmp("-i", argv[i]) == 0) || (strcmp("--input", argv[i]) == 0)) {
			// Set the input file name

			assert(i + 1 < argc); // Check if there's another arg available
			input_file_name = argv[++i];
		}
	}

	return;
}

/**
	* Reads the a file with a list of numbers.
	* The first number is the length of the list.
	* @param{int *} pointer of the length of the list
	* @return{int *} pointer of the number list
	**/
int *read_number_arr_from_file (int *size) {
	FILE *file = NULL;
	int *arr = NULL;
	*size = 0;

	file = fopen(input_file_name, "r");

	fscanf(file, "%d", size);

	arr = (int *) calloc(*size, sizeof(int));

	for (int i = 0; i < *size; i++) {
		fscanf(file, "%d", &arr[i]);
	}

	fclose(file);

	return arr;
}

/**
	* Calculate the average of a list of numbers
	* @param{int} size: size or length of the list of numbers
	* @param{int *} arr: pointer of the list of numbers
	* @return{int} average of the numbers
	**/
int calc_average_from_arr (int size, int *arr) {
	int avg = 0;
	int sum = 0;

	for (int i = 0; i < size; i ++) {
		sum += arr[i];
	}

	avg = sum / size;

	return avg;
}

/**
	* print the program results, average of a number list, and the list itself 
	* in a file
	* @param{int} avg: average of the numbers
	* @param{int} size: length of the number list
	* @param{int *} arr: pointer of the number list
	* @return{void}
	**/
void print_results_to_file (int avg, int size, int *arr) {
	FILE *out_file = NULL;

	out_file = fopen(output_file_name, "w+");

	fprintf(out_file, "Numbers: ");

	for (int i = 0; i < size; i ++) {
		fprintf(out_file, "%d\t", arr[i]);
	}

	fprintf(out_file, "\n");
	fprintf(out_file, "Average: %d\n", avg);

	fclose(out_file);

	return;
}

/** 
	* Main function, command line args
	* -o | --output OUTPUT_FILE: Flag that sets the Name of the OUTPUT FILE
	* -i | --input  INPUT_FILE: Flag that sets the Name of the INPUT FILE
	*@return{int} 0
	**/
int main (int argc, char *argv[]) {
	int *number_arr;
	int size = 0;
	int avg = 0;

	// Handle Command line Args
	if (argc >= 2) {
		handle_command_line_args (argc, argv);
	}

	number_arr = read_number_arr_from_file(&size);

	avg = calc_average_from_arr(size, number_arr);

	print_results_to_file(avg, size, number_arr);

	return 0;
}
