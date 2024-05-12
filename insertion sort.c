#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include the time.h header for clock()

// Function to perform insertion sort
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead
        // of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Main function to control program execution
int main() {
    clock_t start, end; // Variables to store the start and end times
    double cpu_time_used;
    int *arr;
    int n, i;
    FILE *file;

    start = clock(); // Start the timer

    // Open the file for reading
    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    // Read the number of elements
    if (fscanf(file, "%d", &n) != 1) {
        printf("Error reading number of elements\n");
        fclose(file);
        return 1;
    }

    // Allocate memory based on the number of elements
    arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        fclose(file);
        return 1;
    }

    // Read the integers from the file
    for (i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            printf("Error reading integers from file\n");
            free(arr);
            fclose(file);
            return 1;
        }
    }

    // Close the file
    fclose(file);

    // Sort the array using insertion sort
    insertionSort(arr, n);

    // Free the dynamically allocated memory
    free(arr);

    end = clock(); // Stop the timer
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed CPU time in seconds

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
