#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Maximum
    int max = a[0];

    for (int i = 1; i < n; i++)
        if (a[i] > max)
            max = a[i];

    printf("Maximum = %d\n", max);

    // Mean
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += a[i];

    double mean = sum / n;

    printf("Mean = %.2f\n", mean);

    // Standard deviation
    double variance = 0;

    for (int i = 0; i < n; i++)
        variance += (a[i] - mean) * (a[i] - mean);

    variance /= n;

    printf("Standard Deviation = %.2f\n",
           sqrt(variance));

    // Reverse
    for (int i = 0; i < n / 2; i++) {
        int temp = a[i];
        a[i] = a[n - i - 1];
        a[n - i - 1] = temp;
    }

    printf("Reversed array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");

    return 0;
}