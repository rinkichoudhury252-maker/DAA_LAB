
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int root;
    int index;
    int value;
} Item;

int *parent, *sz;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;

    if (sz[a] < sz[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
}

int cmpItem(const void *a, const void *b) {
    const Item *x = a, *y = b;

    if (x->root != y->root)
        return (x->root > y->root) - (x->root < y->root);

    return (x->index > y->index) -
           (x->index < y->index);
}

int cmpInt(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int n, m;

    scanf("%d%d", &n, &m);

    int *A = malloc(n * sizeof(int));
    parent = malloc(n * sizeof(int));
    sz = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
        parent[i] = i;
        sz[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        unite(u, v);
    }

    Item *items = malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        items[i].root = find(i);
        items[i].index = i;
        items[i].value = A[i];
    }

    qsort(items, n, sizeof(Item), cmpItem);

    int *values = malloc(n * sizeof(int));

    int start = 0;

    while (start < n) {
        int end = start + 1;

        while (end < n &&
               items[end].root == items[start].root)
            end++;

        int len = end - start;

        for (int j = 0; j < len; j++)
            values[j] = items[start + j].value;

        qsort(values, len, sizeof(int), cmpInt);

        for (int j = 0; j < len; j++)
            A[items[start + j].index] = values[j];

        start = end;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);

    printf("\n");

    free(A);
    free(parent);
    free(sz);
    free(items);
    free(values);

    return 0;
}
