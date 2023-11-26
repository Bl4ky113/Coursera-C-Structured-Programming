#include <stdio.h>


int main() {
    FILE *inputFile, *outputFile;
    int size, i, max;
    double average;

    // Open the input file for reading
    inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        fprintf(stderr, "Error opening input file.\n");
        return 1;
    }

    // Read the size of the array
    fscanf(inputFile, "%d", &size);

    // Check if the size is non-positive
    if (size <= 0) {
        fprintf(stderr, "Invalid array size.\n");
        fclose(inputFile);
        return 1;
    }

    // Allocate memory for the array
    int *data = (int *)malloc(size * sizeof(int));

    // Read integers into the array
    for (i = 0; i < size; i++) {
        fscanf(inputFile, "%d", &data[i]);
    }

    // Close the input file
    fclose(inputFile);

    // Calculate the average
    average = 0.0;
    for (i = 0; i < size; i++) {
        average += data[i];
    }
    average /= size;

    // Find the maximum value
    max = data[0];
    for (i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        }
    }

    // Open the output file for writing
    outputFile = fopen("answer-hw3.txt", "w");
    if (outputFile == NULL) {
        fprintf(stderr, "Error opening output file.\n");
        free(data); // Free allocated memory before exiting
        return 1;
    }

    // Print the results to the screen
    printf("Array elements: ");
    for (i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");

    printf("Average: %.2f\n", average);
    printf("Maximum: %d\n", max);

    // Print the results to the output file
    fprintf(outputFile, "Array elements: ");
    for (i = 0; i < size; i++) {
        fprintf(outputFile, "%d ", data[i]);
    }
    fprintf(outputFile, "\n");

    fprintf(outputFile, "Average: %.2f\n", average);
    fprintf(outputFile, "Maximum: %d\n", max);

    // Close the output file
    fclose(outputFile);

    // Free allocated memory
    free(data);

    return 0;
}
