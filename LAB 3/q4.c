#include <stdio.h>
#include <math.h>

long long moveCount = 0;

void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 0) return;
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    moveCount++;
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    printf("Enter number of disks: ");
    scanf("%d", &n);

    moveCount = 0;
    towerOfHanoi(n, 'A', 'C', 'B');
    printf("\nTotal moves required: %lld\n", moveCount);

    return 0;
}
