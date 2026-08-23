#include <stdio.h>
#include <stdlib.h>

/* Merge two sorted parts */
void merge(int a[], int l, int m, int r) {
    int i = l, j = m + 1, k = 0;
    int temp[r - l + 1];

    while (i <= m && j <= r) {
        if (a[i] < a[j])
            temp[k++] = a[i++];
        else
            temp[k++] = a[j++];
    }

    while (i <= m)
        temp[k++] = a[i++];

    while (j <= r)
        temp[k++] = a[j++];

    for (i = l, k = 0; i <= r; i++, k++)
        a[i] = temp[k];
}

/* Merge Sort */
void mergeSort(int a[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

/* Binary Search */
int binarySearch(int a[], int n, int key) {
    int l = 0, r = n - 1;

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m] == key)
            return m;

        if (a[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}

/* Check whether index is already selected */
int isSelected(int selected[], int count, int index) {
    for (int i = 0; i < count; i++) {
        if (selected[i] == index)
            return 1;
    }
    return 0;
}

/* Generate combinations of k-1 elements */
int findCombination(int S[], int n, int k,
                    int depth, int start,
                    int selected[], int sum, int T) {

    /* k-1 elements have been selected */
    if (depth == k - 1) {
        int required = T - sum;
        int index = binarySearch(S, n, required);

        if (index != -1 && !isSelected(selected, k - 1, index)) {
            printf("Elements found: ");

            for (int i = 0; i < k - 1; i++)
                printf("%d ", S[selected[i]]);

            printf("%d\n", required);

            return 1;
        }

        return 0;
    }

    for (int i = start; i < n; i++) {
        selected[depth] = i;

        if (findCombination(S, n, k, depth + 1,
                            i + 1, selected,
                            sum + S[i], T))
            return 1;
    }

    return 0;
}

int main() {
    int n, k, T;

    printf("Enter n: ");
    scanf("%d", &n);

    int S[n];

    printf("Enter elements of S:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &S[i]);

    printf("Enter k: ");
    scanf("%d", &k);

    printf("Enter T: ");
    scanf("%d", &T);

    /* Sort the set */
    mergeSort(S, 0, n - 1);

    int selected[k - 1];

    if (!findCombination(S, n, k, 0, 0,
                         selected, 0, T))
        printf("No such combination exists.\n");

    return 0;
}