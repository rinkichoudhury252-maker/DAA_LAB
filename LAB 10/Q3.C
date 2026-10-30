
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *parent, *sz;
long long *sum;

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
    sum[a] += sum[b];
}

int main(void) {
    int V, E, K;

    printf("Enter V, E and K: ");
    scanf("%d%d%d", &V, &E, &K);

    parent = malloc(V * sizeof(int));
    sz = malloc(V * sizeof(int));
    sum = malloc(V * sizeof(long long));

    for (int i = 0; i < V; i++) {
        parent[i] = i;
        sz[i] = 1;
        scanf("%lld", &sum[i]);
    }

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        unite(u, v);

        long long best = LLONG_MIN;
        int found = 0;

        for (int j = 0; j < V; j++) {
            if (find(j) == j && sz[j] <= K) {
                if (!found || sum[j] > best)
                    best = sum[j];
                found = 1;
            }
        }

        if (found)
            printf("%lld\n", best);
        else
            printf("No eligible component\n");
    }

    free(parent);
    free(sz);
    free(sum);
    return 0;
}
