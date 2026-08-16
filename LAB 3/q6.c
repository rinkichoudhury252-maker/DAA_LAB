#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* ---------- Method 1: Brute force O(n^2) ---------- */
int has_duplicate_bruteforce(int *arr, int n) {
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] == arr[j]) return 1;
    return 0;
}

/* ---------- Method 2: Sort then scan O(n log n) ---------- */
int cmp_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int has_duplicate_sort(int *arr, int n) {
    int *copy = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) copy[i] = arr[i];

    qsort(copy, n, sizeof(int), cmp_int);

    int found = 0;
    for (int i = 0; i < n - 1; i++) {
        if (copy[i] == copy[i + 1]) { found = 1; break; }
    }
    free(copy);
    return found;
}

/* ---------- Method 3: Hash set O(n) average ---------- */
typedef struct Node {
    int value;
    struct Node *next;
} Node;

int has_duplicate_hash(int *arr, int n) {
    int table_size = n * 2 + 1;          // simple sizing to keep load factor reasonable
    Node **table = calloc(table_size, sizeof(Node *));
    int found = 0;

    for (int i = 0; i < n && !found; i++) {
        int val = arr[i];
        unsigned int h = ((unsigned int)val) % table_size;

        Node *cur = table[h];
        while (cur != NULL) {
            if (cur->value == val) { found = 1; break; }
            cur = cur->next;
        }
        if (!found) {
            Node *node = malloc(sizeof(Node));
            node->value = val;
            node->next = table[h];
            table[h] = node;
        }
    }

    // free the table
    for (int i = 0; i < table_size; i++) {
        Node *cur = table[i];
        while (cur != NULL) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }
    free(table);
    return found;
}

/* ---------- Demo / benchmark ---------- */
void shuffle(int *arr, int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        int t = arr[i]; arr[i] = arr[j]; arr[j] = t;
    }
}

int main(int argc, char *argv[]) {
    int n = (argc > 1) ? atoi(argv[1]) : 10000;
    int method = (argc > 2) ? atoi(argv[2]) : 0; // 0=all, 1=brute, 2=sort, 3=hash

    srand(1);
    int *arr = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++) arr[i] = i;  // guaranteed unique -> worst case
    shuffle(arr, n);

    clock_t start, end;

    if (method == 0 || method == 1) {
        start = clock();
        int r1 = has_duplicate_bruteforce(arr, n);
        end = clock();
        printf("Brute force : found=%d  time=%f s\n", r1, (double)(end - start) / CLOCKS_PER_SEC);
    }
    if (method == 0 || method == 2) {
        start = clock();
        int r2 = has_duplicate_sort(arr, n);
        end = clock();
        printf("Sort-based  : found=%d  time=%f s\n", r2, (double)(end - start) / CLOCKS_PER_SEC);
    }
    if (method == 0 || method == 3) {
        start = clock();
        int r3 = has_duplicate_hash(arr, n);
        end = clock();
        printf("Hash-based  : found=%d  time=%f s\n", r3, (double)(end - start) / CLOCKS_PER_SEC);
    }

    free(arr);
    return 0;
}