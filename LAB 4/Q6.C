#include <stdio.h>
#include <stdlib.h>

struct Interval {
    int start;
    int end;
};

/* Compare intervals by starting point */
int compare(const void *a, const void *b) {
    struct Interval *i1 = (struct Interval *)a;
    struct Interval *i2 = (struct Interval *)b;

    return i1->start - i2->start;
}

int main() {
    int n;

    printf("Enter number of intervals: ");
    scanf("%d", &n);

    struct Interval intervals[n];
    struct Interval result[n];

    printf("Enter intervals:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d %d",
              &intervals[i].start,
              &intervals[i].end);
    }

    /* Sort intervals by starting point */
    qsort(intervals, n, sizeof(struct Interval), compare);

    int count = 0;

    result[count++] = intervals[0];

    /* Merge overlapping intervals */
    for (int i = 1; i < n; i++) {

        if (intervals[i].start <= result[count - 1].end) {

            if (intervals[i].end > result[count - 1].end)
                result[count - 1].end = intervals[i].end;

        } else {
            result[count++] = intervals[i];
        }
    }

    printf("\nMerged intervals:\n");

    for (int i = 0; i < count; i++) {
        printf("(%d, %d) ", result[i].start, result[i].end);
    }

    printf("\n");

    return 0;
}