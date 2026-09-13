#include <stdio.h>

long long minMoves(int n)
{
    if (n == 1)
        return 1;

    if (n == 2)
        return 2;

    long long a = 1;  // M(1)
    long long b = 2;  // M(2)
    long long c;

    for (int i = 3; i <= n; i++)
    {
        c = b + 2 * a + 1;

        a = b;
        b = c;
    }

    return b;
}

int main()
{
    int n;

    printf("Enter number of switches: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of switches.\n");
        return 0;
    }

    printf("Minimum number of moves = %lld\n",
           minMoves(n));

    return 0;
}