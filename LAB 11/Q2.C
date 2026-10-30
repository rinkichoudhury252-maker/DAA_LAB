#include <stdio.h>
#include <stdlib.h>

#define MAX 100005

typedef struct Edge {
    int to;
    struct Edge *next;
} Edge;

Edge *graph[MAX];
int dist[MAX], owner[MAX], queue[MAX];

void addEdge(int u, int v) {
    Edge *e = malloc(sizeof(Edge));
    e->to = v;
    e->next = graph[u];
    graph[u] = e;

    e = malloc(sizeof(Edge));
    e->to = u;
    e->next = graph[v];
    graph[v] = e;
}

int main(void) {
    int V, E, K, R;

    scanf("%d %d", &V, &E);

    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
    }

    scanf("%d %d", &K, &R);

    int hubs[MAX];

    for (int i = 0; i < K; i++)
        scanf("%d", &hubs[i]);

    for (int i = 0; i < V; i++) {
        dist[i] = -1;
        owner[i] = -1;
    }

    /* Sort hubs by increasing index */
    for (int i = 0; i < K - 1; i++) {
        for (int j = i + 1; j < K; j++) {
            if (hubs[i] > hubs[j]) {
                int t = hubs[i];
                hubs[i] = hubs[j];
                hubs[j] = t;
            }
        }
    }

    int front = 0, rear = 0;

    for (int i = 0; i < K; i++) {
        int h = hubs[i];

        if (dist[h] == -1) {
            dist[h] = 0;
            owner[h] = i + 1;
            queue[rear++] = h;
        }
    }

    while (front < rear) {
        int u = queue[front++];

        for (Edge *e = graph[u]; e; e = e->next) {
            int v = e->to;

            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                owner[v] = owner[u];
                queue[rear++] = v;
            }
        }
    }

    printf("Vertex\tOwner\tDistance\n");

    for (int v = 0; v < V; v++) {
        if (dist[v] == -1 || dist[v] > R)
            printf("%d\t-1\t%d\n", v, dist[v]);
        else
            printf("%d\t%d\t%d\n", v, owner[v], dist[v]);
    }

    return 0;
}