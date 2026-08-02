#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define N 1000000.0  // Large n for comparison

// Structure to hold function name and computed value
typedef struct {
    char name[50];
    double value;
} FuncVal;

// Comparison function for qsort
int compare(const void *a, const void *b) {
    double diff = ((FuncVal*)a)->value - ((FuncVal*)b)->value;
    return (diff > 0) - (diff < 0);
}

int main() {
    FuncVal funcs[] = {
        {"1", 1},
        {"12*sqrt(n)", 12 * sqrt(N)},
        {"50*n^0.5", 50 * pow(N, 0.5)},
        {"n^0.51", pow(N, 0.51)},
        {"n", N},
        {"3n", 3 * N},
        {"n*log2(n)", N * (log(N) / log(2))},
        {"n*log2(n) (duplicate)", N * (log(N) / log(2))},
        {"232*n*log2(n)", 232 * N * (log(N) / log(2))},
        {"100n^2 + 6n", 100 * pow(N, 2) + 6 * N},
        {"n^2 - 324", pow(N, 2) - 324},
        {"2n^3", 2 * pow(N, 3)}
    };

    int count = sizeof(funcs) / sizeof(funcs[0]);

    // Sort by computed value
    qsort(funcs, count, sizeof(FuncVal), compare);

    // Print sorted order
    printf("Functions in increasing order of growth for n = %.0f:\n", N);
    for (int i = 0; i < count; i++) {
        printf("%2d. %-25s => %.2e\n", i + 1, funcs[i].name, funcs[i].value);
    }

    return 0;
}
