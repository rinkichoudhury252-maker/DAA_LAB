#include <stdio.h>

void sort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j]) {
                int t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
}

int main() {

    int n;
    printf("Enter number of sticks: ");
    scanf("%d", &n);

    int a[100];

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int total = 0;

    while (n > 1) {

        sort(a, n);

        int cost = a[0] + a[1];

        total += cost;

        for (int i = 2; i < n; i++)
            a[i - 2] = a[i];

        a[n - 2] = cost;
        n--;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}