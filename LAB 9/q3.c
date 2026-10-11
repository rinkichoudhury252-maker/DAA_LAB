#include <stdio.h>

typedef struct {
    int distance;
    int fuel;
} Station;

int main() {
    int n, D, F;

    printf("Enter number of stations: ");
    scanf("%d", &n);

    Station s[n];

    for (int i = 0; i < n; i++)
        scanf("%d %d", &s[i].distance, &s[i].fuel);

    printf("Enter target distance and initial fuel: ");
    scanf("%d %d", &D, &F);

    int stops = 0;
    int used[n];

    for (int i = 0; i < n; i++)
        used[i] = 0;

    while (F < D) {

        int best = -1;

        for (int i = 0; i < n; i++) {
            if (!used[i] && s[i].distance <= F) {
                if (best == -1 ||
                    s[i].fuel > s[best].fuel)
                    best = i;
            }
        }

        if (best == -1) {
            printf("Target cannot be reached\n");
            return 0;
        }

        F += s[best].fuel;
        used[best] = 1;
        stops++;
    }

    printf("Minimum stops = %d\n", stops);

    return 0;
}