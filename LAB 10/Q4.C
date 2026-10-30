
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int *parent, *sz;
long long *weight, *sum;
int **adj, *active;

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

long long maximumComponent(int V) {
    long long best = LLONG_MIN;
    int found = 0;

    for (int i = 1; i <= V; i++) {
        if (active[i] && find(i) == i) {
            if (!found || sum[i] > best)
                best = sum[i];
            found = 1;
        }
    }

    return found ? best : 0;
}

int main(void) {
    int V, E;

    scanf("%d%d", &V, &E);

    parent = malloc((V + 1) * sizeof(int));
    sz = calloc(V + 1, sizeof(int));
    weight = malloc((V + 1) * sizeof(long long));
    sum = calloc(V + 1, sizeof(long long));
    active = calloc(V + 1, sizeof(int));

    adj = malloc((V + 1) * sizeof(int *));

    for (int i = 1; i <= V; i++)
        adj[i] = calloc(V + 1, sizeof(int));

    for (int i = 1; i <= V; i++)
        scanf("%lld", &weight[i]);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }

    int *P = malloc(V * sizeof(int));
    long long *ans = malloc(V * sizeof(long long));

    for (int i = 0; i < V; i++)
        scanf("%d", &P[i]);

    for (int i = V - 1; i >= 0; i--) {
        ans[i] = maximumComponent(V);

        int u = P[i];
        active[u] = 1;
        parent[u] = u;
        sz[u] = 1;
        sum[u] = weight[u];

        for (int v = 1; v <= V; v++) {
            if (active[v] && adj[u][v])
                unite(u, v);
        }
    }

    for (int i = 0; i < V; i++)
        printf("%lld\n", ans[i]);

    for (int i = 1; i <= V; i++)
        free(adj[i]);

    free(adj);
    free(parent);
    free(sz);
    free(weight);
    free(sum);
    free(active);
    free(P);
    free(ans);

    return 0;
}
