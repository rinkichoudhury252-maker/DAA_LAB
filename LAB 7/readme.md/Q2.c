#include <stdio.h>

#define MAX_EGGS 20
#define MAX_FLOORS 100

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int eggDrop(int E, int F)
{
    int dp[MAX_EGGS + 1][MAX_FLOORS + 1];
    int e, f, x;

    // Base cases
    for (e = 1; e <= E; e++)
    {
        dp[e][0] = 0;
        dp[e][1] = 1;
    }

    // With one egg, test every floor sequentially
    for (f = 1; f <= F; f++)
    {
        dp[1][f] = f;
    }

    // Dynamic programming
    for (e = 2; e <= E; e++)
    {
        for (f = 2; f <= F; f++)
        {
            dp[e][f] = F;

            for (x = 1; x <= f; x++)
            {
                int broken = dp[e - 1][x - 1];
                int notBroken = dp[e][f - x];

                int worstCase = 1 + max(broken, notBroken);

                dp[e][f] = min(dp[e][f], worstCase);
            }
        }
    }

    return dp[E][F];
}

int main()
{
    int E, F, result;

    printf("Enter number of eggs: ");
    scanf("%d", &E);

    printf("Enter number of floors: ");
    scanf("%d", &F);

    if (E <= 0 || E > MAX_EGGS || F < 0 || F > MAX_FLOORS)
    {
        printf("Invalid input.\n");
        return 1;
    }

    result = eggDrop(E, F);

    printf("\nMinimum number of droppings required = %d\n", result);

    return 0;
}