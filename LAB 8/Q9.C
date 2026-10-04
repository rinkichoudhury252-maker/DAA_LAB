#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

unsigned long long collatzStep(unsigned long long n) {

    if (n % 2 == 0)
        return n / 2;

    return 3 * n + 1;
}

void analyse(unsigned long long n) {

    unsigned long long start = n;

    unsigned long long steps = 0;
    unsigned long long maxValue = n;

    printf("\nStarting value: %llu\n", n);
    printf("Trajectory: ");

    while (n != 1) {

        printf("%llu -> ", n);

        if (n > ULLONG_MAX / 3) {
            printf("\nOverflow detected.\n");
            return;
        }

        n = collatzStep(n);

        if (n > maxValue)
            maxValue = n;

        steps++;
    }

    printf("1\n");

    printf("Steps = %llu\n", steps);
    printf("Maximum value = %llu\n", maxValue);
}

int main() {

    unsigned long long a, b;

    printf("Enter interval [a,b]: ");
    scanf("%llu %llu", &a, &b);

    if (a == 0 || a > b) {
        printf("Invalid interval.\n");
        return 1;
    }

    for (unsigned long long n = a; n <= b; n++) {

        analyse(n);

        if (n == ULLONG_MAX)
            break;
    }

    return 0;
}