#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Include for clock() function

// Function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Function to read array from file
int *readArrayFromFile(FILE *file, int *n) {
    if (fscanf(file, "%d", n) != 1) {
        fprintf(stderr, "Error reading the number of elements.\n");
        return NULL;
    }

    int *arr = (int *)malloc(*n * sizeof(int));
    if (arr == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }

    for (int i = 0; i < *n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            fprintf(stderr, "Error reading element from the file.\n");
            free(arr);
            return NULL;
        }
    }
    return arr;
}

int main() {
    FILE *file;
    int *arr;
    int n;
    clock_t start, end;
    double cpu_time_used;

    file = fopen("numbers.txt", "r");
    if (file == NULL) {
        perror("Error opening file");
        return 1;
    }

    arr = readArrayFromFile(file, &n);
    fclose(file);

    if (arr == NULL) {
        return 1; // Error reading the file or memory allocation failed
    }

    start = clock(); // Start the timer
    quickSort(arr, 0, n - 1);
    end = clock(); // End the timer

    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC; // Calculate the elapsed CPU time in seconds
    printf("CPU time used: %f seconds\n", cpu_time_used);

    free(arr); // Free the dynamically allocated memory
    return 0;
}
