/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for seeding the random number generator with the current time

int main() {
    FILE *file;
    int i;
    int num;

    // Seed the random number generator to get different results each time
    srand(time(NULL));

    // Open the file for writing
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Generate 1000 random numbers and write them to the file
    for (i = 0; i < 100000; i++) {
        num = rand(); // Generate a random number
        fprintf(file, "%d\n", num); // Write the number to the file followed by a newline
    }

    // Close the file
    fclose(file);

    printf("100000 random numbers have been written to numbers.txt\n");

    return 0;
}
*/
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for seeding the random number generator with the current time

int main() {
    FILE *file;
    int i;

    // Seed the random number generator to get different results each time
    srand(time(NULL));

    // Open the file for writing
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Generate and write the first 50000 sorted numbers to the file
    for (i = 1; i <= 50000; i++) {
        fprintf(file, "%d\n", i);  // Write the number to the file followed by a newline
    }

    // Generate and write the next 50000 random numbers to the file
    for (i = 0; i < 50000; i++) {
        int num = rand();  // Generate a random number
        fprintf(file, "%d\n", num);  // Write the number to the file followed by a newline
    }

    // Close the file
    fclose(file);

    printf("100000 numbers have been written to numbers.txt, with the first 50000 sorted.\n");

    return 0;
}
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>  // for seeding the random number generator with the current time

int main() {
    FILE *file;
    int i;

    // Open the file for writing
    file = fopen("numbers.txt", "w");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Generate and write the sorted numbers to the file
    for (i = 1; i <= 100000; i++) {
        fprintf(file, "%d\n", i);  // Write the number to the file followed by a newline
    }

    // Close the file
    fclose(file);

    printf("100000 sorted numbers have been written to numbers.txt\n");

    return 0;
}
