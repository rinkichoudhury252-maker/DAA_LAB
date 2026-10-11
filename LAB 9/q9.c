#include <stdio.h>
#include <limits.h>

int main() {

    int n;

    printf("Enter number of weights: ");
    scanf("%d", &n);

    int w[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    int total = 0;

    while (n > 1) {

        int pos = 0;
        int minimum = INT_MAX;

        for (int i = 0; i < n - 1; i++) {

            int sum = w[i] + w[i + 1];

            if (sum < minimum) {
                minimum = sum;
                pos = i;
            }
        }

        total += minimum;

        w[pos] = minimum;

        for (int i = pos + 1; i < n - 1; i++)
            w[i] = w[i + 1];

        n--;
    }

    printf("Total merge cost = %d\n", total);

    return 0;
}