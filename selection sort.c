#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include for clock() function and clock_t type

// Function to swap the position of two elements
void swap(int *xp, int *yp) {
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// Function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in the unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// Main function to control program execution
int main() {
    int *arr;
    int n, i;
    FILE *file;
    clock_t start, end; // Variables to store the start and end times
    double cpu_time_used;

    start = clock(); // Start the timer

    file = fopen("numbers.txt", "r"); // Open the file for reading
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    if (fscanf(file, "%d", &n) != 1) { // Read the number of elements
        printf("Error reading the number of elements.\n");
        fclose(file);
        return 1;
    }

    arr = (int*)malloc(n * sizeof(int)); // Allocate memory for n elements
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) { // Read each element into arr
            printf("Error reading an element from the file.\n");
            free(arr);
            fclose(file);
            return 1;
        }
    }

    fclose(file); // Close the file

    selectionSort(arr, n); // Sort the array
    free(arr); // Free the dynamically allocated memory

    end = clock(); // Stop the timer
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed CPU time in seconds

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
