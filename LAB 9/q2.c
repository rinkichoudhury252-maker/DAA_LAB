#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char ch;
    int freq;
    struct Node *left, *right;
} Node;

Node *createNode(char ch, int freq) {
    Node *n = (Node *)malloc(sizeof(Node));
    n->ch = ch;
    n->freq = freq;
    n->left = n->right = NULL;
    return n;
}

void swap(Node **a, Node **b) {
    Node *t = *a;
    *a = *b;
    *b = t;
}

void sort(Node *arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i]->freq > arr[j]->freq)
                swap(&arr[i], &arr[j]);
}

void printCodes(Node *root, int code[], int top) {
    if (root->left) {
        code[top] = 0;
        printCodes(root->left, code, top + 1);
    }

    if (root->right) {
        code[top] = 1;
        printCodes(root->right, code, top + 1);
    }

    if (!root->left && !root->right) {
        printf("%c : ", root->ch);
        for (int i = 0; i < top; i++)
            printf("%d", code[i]);
        printf("\n");
    }
}

int main() {
    int n;

    printf("Enter number of symbols: ");
    scanf("%d", &n);

    Node *arr[100];

    for (int i = 0; i < n; i++) {
        char ch;
        int freq;

        printf("Enter symbol and frequency: ");
        scanf(" %c %d", &ch, &freq);

        arr[i] = createNode(ch, freq);
    }

    int size = n;

    while (size > 1) {
        sort(arr, size);

        Node *left = arr[0];
        Node *right = arr[1];

        Node *parent =
            createNode('$', left->freq + right->freq);

        parent->left = left;
        parent->right = right;

        for (int i = 2; i < size; i++)
            arr[i - 2] = arr[i];

        arr[size - 2] = parent;
        size--;
    }

    int code[100];

    printf("\nHuffman Codes:\n");
    printCodes(arr[0], code, 0);

    return 0;
}