#include <stdio.h>

typedef struct {
    double value, weight, decay;
} Item;

int main() {
    int n;
    double W;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item a[n];

    for (int i = 0; i < n; i++) {
        printf("Enter value, weight and decay rate: ");
        scanf("%lf %lf %lf",
              &a[i].value, &a[i].weight, &a[i].decay);
    }

    printf("Enter capacity: ");
    scanf("%lf", &W);

    double total = 0, t = 0;

    while (W > 0) {
        int best = -1;
        double bestDensity = -1e9;

        for (int i = 0; i < n; i++) {
            if (a[i].weight > 0) {
                double d = a[i].value / a[i].weight
                           - a[i].decay * t;

                if (d > bestDensity) {
                    bestDensity = d;
                    best = i;
                }
            }
        }

        if (best == -1 || bestDensity <= 0)
            break;

        double take = (a[best].weight < W)
                    ? a[best].weight : W;

        total += take * bestDensity;
        W -= take;
        t += take;

        a[best].weight -= take;
    }

    printf("Maximum value = %.2lf\n", total);

    return 0;
}