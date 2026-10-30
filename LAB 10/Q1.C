
#include <stdio.h>

#define MAX 1005

int parent[MAX], sz[MAX], parity[MAX];

int find(int x) {
    if (parent[x] != x) {
        int p = parent[x];
        parent[x] = find(p);
        parity[x] ^= parity[p];
    }
    return parent[x];
}

int addEdge(int u, int v) {
    int ru = find(u), pu = parity[u];
    int rv = find(v), pv = parity[v];

    if (ru == rv)
        return (pu ^ pv) == 1;

    if (sz[ru] < sz[rv]) {
        parent[ru] = rv;
        parity[ru] = pu ^ pv ^ 1;
        sz[rv] += sz[ru];
    } else {
        parent[rv] = ru;
        parity[rv] = pu ^ pv ^ 1;
        sz[ru] += sz[rv];
    }
    return 1;
}

int main(void) {
    int V, E, u, v;

    printf("Enter vertices and edges: ");
    scanf("%d%d", &V, &E);

    for (int i = 1; i <= V; i++) {
        parent[i] = i;
        sz[i] = 1;
        parity[i] = 0;
    }

    for (int i = 1; i <= E; i++) {
        printf("Enter edge %d: ", i);
        scanf("%d%d", &u, &v);

        if (addEdge(u, v))
            printf("Edge accepted. Graph is bipartite.\n");
        else
            printf("Edge rejected. Bipartiteness violated.\n");
    }

    return 0;
}
