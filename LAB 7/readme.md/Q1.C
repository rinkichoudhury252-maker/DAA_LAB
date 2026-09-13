#include <stdio.h>

int main()
{
    int n;
    int coins, moves;

    printf("Enter the number of rows: ");
    scanf("%d", &n);

    // Total number of coins
    coins = n * (n + 1) / 2;

    // Minimum number of moves
    moves = coins / 3;

    printf("Total number of coins = %d\n", coins);
    printf("Minimum number of moves = %d\n", moves);

    return 0;
}