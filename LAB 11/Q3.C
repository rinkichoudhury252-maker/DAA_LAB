#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 100005
#define HASH_SIZE 262147
#define LEN 11

char words[MAXN][LEN];
int table[HASH_SIZE];
int distA[MAXN], distB[MAXN];
int frontA[MAXN], frontB[MAXN];
int nextA[MAXN], nextB[MAXN];

unsigned long hashWord(const char *s) {
    unsigned long h = 0;
    while (*s)
        h = h * 31 + (unsigned char)*s++;
    return h % HASH_SIZE;
}

int findWord(const char *s) {
    unsigned long h = hashWord(s);

    while (table[h] != 0) {
        int id = table[h] - 1;
        if (strcmp(words[id], s) == 0)
            return id;
        h = (h + 1) % HASH_SIZE;
    }

    return -1;
}

void insertWord(int id) {
    unsigned long h = hashWord(words[id]);

    while (table[h] != 0)
        h = (h + 1) % HASH_SIZE;

    table[h] = id + 1;
}

int expandLayer(int *frontier, int size, int *next,
                int *dist, int *otherDist, int total) {
    int nextSize = 0;
    int best = -1;

    for (int i = 0; i < size; i++) {
        int u = frontier[i];
        char candidate[LEN];
        strcpy(candidate, words[u]);

        for (int p = 0; candidate[p]; p++) {
            char original = candidate[p];

            for (char c = 'a'; c <= 'z'; c++) {
                if (c == original)
                    continue;

                candidate[p] = c;
                int v = findWord(candidate);

                if (v != -1 && dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    next[nextSize++] = v;
                }

                if (v != -1 && otherDist[v] != -1) {
                    int d = dist[u] + 1 + otherDist[v];

                    if (best == -1 || d < best)
                        best = d;
                }
            }

            candidate[p] = original;
        }
    }

    for (int i = 0; i < nextSize; i++)
        frontier[i] = next[i];

    return best == -1 ? nextSize : -best;
}

int main(void) {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%10s", words[i]);
        insertWord(i);
    }

    char A[LEN], B[LEN];
    scanf("%10s %10s", A, B);

    int start = findWord(A);
    int target = findWord(B);

    if (strcmp(A, B) == 0) {
        printf("Minimum mutations = 0\n");
        return 0;
    }

    if (target == -1) {
        printf("Minimum mutations = -1\n");
        return 0;
    }

    if (start == -1) {
        start = N;
        strcpy(words[N], A);
        insertWord(N);
        N++;
    }

    for (int i = 0; i < N; i++)
        distA[i] = distB[i] = -1;

    int sizeA = 1, sizeB = 1;
    frontA[0] = start;
    frontB[0] = target;
    distA[start] = 0;
    distB[target] = 0;

    while (sizeA > 0 && sizeB > 0) {
        int result;

        if (sizeA <= sizeB) {
            result = expandLayer(frontA, sizeA, nextA,
                                 distA, distB, N);

            if (result < 0) {
                printf("Minimum mutations = %d\n", -result);
                return 0;
            }

            sizeA = result;
        } else {
            result = expandLayer(frontB, sizeB, nextB,
                                 distB, distA, N);

            if (result < 0) {
                printf("Minimum mutations = %d\n", -result);
                return 0;
            }

            sizeB = result;
        }
    }

    printf("Minimum mutations = -1\n");
    return 0;
}