#include <stdio.h>
#include <limits.h>

int main() {

    int n;
    scanf("%d", &n);

    int a[n];

    int minVal = INT_MAX;

    for (int i = 0; i < n; i++) {

        scanf("%d", &a[i]);

        if (a[i] % 2 != 0)
            a[i] *= 2;

        if (a[i] < minVal)
            minVal = a[i];
    }

    int answer = INT_MAX;

    while (1) {

        int maxIndex = 0;

        for (int i = 1; i < n; i++)
            if (a[i] > a[maxIndex])
                maxIndex = i;

        int maxVal = a[maxIndex];

        if (maxVal - minVal < answer)
            answer = maxVal - minVal;

        if (maxVal % 2 != 0)
            break;

        a[maxIndex] /= 2;

        if (a[maxIndex] < minVal)
            minVal = a[maxIndex];
    }

    printf("Minimum deviation = %d\n", answer);

    return 0;
}