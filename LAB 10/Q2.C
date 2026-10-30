
#include <stdio.h>
#include <stdlib.h>

int *parent, *sz, R, C;

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

int unite(int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return 0;

    if (sz[a] < sz[b]) {
        int t = a;
        a = b;
        b = t;
    }

    parent[b] = a;
    sz[a] += sz[b];
    return 1;
}

int main(void) {
    int k, r, c, islands = 0;

    printf("Enter rows, columns and operations: ");
    scanf("%d%d%d", &R, &C, &k);

    int N = R * C;

    parent = malloc(N * sizeof(int));
    sz = calloc(N, sizeof(int));

    for (int i = 0; i < N; i++)
        parent[i] = -1;

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    for (int i = 0; i < k; i++) {
        scanf("%d%d", &r, &c);

        int x = r * C + c;

        if (parent[x] != -1) {
            printf("%d ", islands);
            continue;
        }

        parent[x] = x;
        sz[x] = 1;
        islands++;

        for (int d = 0; d < 4; d++) {
            int nr = r + dr[d];
            int nc = c + dc[d];

            if (nr < 0 || nr >= R ||
                nc < 0 || nc >= C)
                continue;

            int y = nr * C + nc;

            if (parent[y] != -1 && unite(x, y))
                islands--;
        }

        printf("%d ", islands);
    }

    printf("\n");
    free(parent);
    free(sz);
    return 0;
}
