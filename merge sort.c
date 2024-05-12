#include <stdio.h>
#include <stdlib.h>
#include <time.h> // For clock() function and clock_t type

// Function prototypes
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);

// Merge Function
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Merge the temp arrays back into arr[l..r]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort Function
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l + (r - l) / 2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

// Main function
int main() {
    clock_t start, end; // Variables to store the start and end times
    double cpu_time_used;
    int *arr;
    int n, i;
    FILE *file;

    // Start the timer
    start = clock();

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
    arr = (int *)malloc(n * sizeof(int));
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

    // Sort the array using merge sort
    mergeSort(arr, 0, n - 1);

    // Free the dynamically allocated memory
    free(arr);

    // Stop the timer and calculate the CPU time used
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("CPU time used: %f seconds\n", cpu_time_used);

    return 0;
}
