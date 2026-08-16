#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Version 1: Optimized Bubble Sort (Terminates early if already sorted)
long long bubbleSortOptimized(int arr[], int n) {
    long long comparisons = 0;
    int swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = 0;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        // If no two elements were swapped by inner loop, then break
        if (swapped == 0) {
            break;
        }
    }
    return comparisons;
}

// Version 2: Standard Bubble Sort (Always completes n-1 passes)
long long bubbleSortStandard(int arr[], int n) {
    long long comparisons = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    return comparisons;
}

// Helper function to fill array with random numbers
void generateRandomArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000; // Random numbers between 0 and 9999
    }
}

// Helper function to copy an array
void copyArray(int source[], int destination[], int n) {
    for (int i = 0; i < n; i++) {
        destination[i] = source[i];
    }
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Array sizes to simulate (from 100 to 2000, incrementing by 100)
    int sizes[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 
                   1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    // Print CSV Header
    printf("Array_Size,Optimized_Comparisons,Standard_Comparisons\n");

    for (int i = 0; i < num_sizes; i++) {
        int n = sizes[i];
        
        // Dynamically allocate memory for arrays
        int *original = (int *)malloc(n * sizeof(int));
        int *arr1 = (int *)malloc(n * sizeof(int));
        int *arr2 = (int *)malloc(n * sizeof(int));

        // Generate data and make exact copies for a fair comparison
        generateRandomArray(original, n);
        copyArray(original, arr1, n);
        copyArray(original, arr2, n);

        // Run simulations
        long long comp_opt = bubbleSortOptimized(arr1, n);
        long long comp_std = bubbleSortStandard(arr2, n);

        // Print row data
        printf("%d,%lld,%lld\n", n, comp_opt, comp_std);

        // Free memory
        free(original);
        free(arr1);
        free(arr2);
    }

    return 0;
}