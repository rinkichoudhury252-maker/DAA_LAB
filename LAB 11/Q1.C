#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF (INT_MAX / 4)

typedef struct Edge {
    int to, weight;
    struct Edge *next;
} Edge;

typedef struct Node {
    int state;
    struct Node *next;
} Node;

Edge *graph[2005];

Node *front = NULL, *rear = NULL;

void addEdge(int u, int v, int w) {
    Edge *e = malloc(sizeof(Edge));
    e->to = v;
    e->weight = w;
    e->next = graph[u];
    graph[u] = e;
}

void pushFront(int state) {
    Node *n = malloc(sizeof(Node));
    n->state = state;
    n->next = front;
    front = n;
    if (rear == NULL)
        rear = n;
}

void pushBack(int state) {
    Node *n = malloc(sizeof(Node));
    n->state = state;
    n->next = NULL;

    if (rear == NULL)
        front = rear = n;
    else {
        rear->next = n;
        rear = n;
    }
}

int popFront(void) {
    Node *n = front;
    int state = n->state;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(n);
    return state;
}

int empty(void) {
    return front == NULL;
}

int main(void) {
    int V, E, S, C;

    scanf("%d %d %d %d", &V, &E, &S, &C);

    for (int i = 0; i < E; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
    }

    int *dist = malloc(2 * V * sizeof(int));

    for (int i = 0; i < 2 * V; i++)
        dist[i] = INF;

    /* State = 2 * vertex + parity */
    dist[2 * S] = 0;
    pushFront(2 * S);

    while (!empty()) {
        int state = popFront();
        int u = state / 2;
        int parity = state % 2;

        for (Edge *e = graph[u]; e; e = e->next) {
            int v = e->to;
            int w = e->weight;
            int newParity = parity ^ w;
            int nextState = 2 * v + newParity;
            int newDist = dist[state] + w;

            if (newDist < dist[nextState]) {
                dist[nextState] = newDist;

                if (w == 0)
                    pushFront(nextState);
                else
                    pushBack(nextState);
            }
        }
    }

    printf("Vertex\tMinimum Cost\n");

    for (int v = 0; v < V; v++) {
        int even = dist[2 * v];
        int odd = dist[2 * v + 1];
        int answer = INF;

        if (even < answer)
            answer = even;

        if (odd < INF && odd + C < answer)
            answer = odd + C;

        if (answer == INF)
            printf("%d\tUnreachable\n", v);
        else
            printf("%d\t%d\n", v, answer);
    }

    free(dist);
    return 0;
}