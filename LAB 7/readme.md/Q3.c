#include <stdio.h>
#include <limits.h>

#define MAX 30

long long dp[MAX + 1];
int split[MAX];

long long powerOfTwo(int n)
{
    return 1LL << n;
}

void calculate()
{
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 3;

    for (int n = 3; n <= MAX; n++)
    {
        dp[n] = LLONG_MAX;

        for (int k = 1; k < n; k++)
        {
            long long moves =
                2 * dp[k] + powerOfTwo(n - k) - 1;

            if (moves < dp[n])
            {
                dp[n] = moves;
                split[n] = k;
            }
        }
    }
}

int main()
{
    int n;

    calculate();

    printf("Enter number of disks: ");
    scanf("%d", &n);

    if (n < 1 || n > MAX)
    {
        printf("Invalid number of disks.\n");
        return 0;
    }

    printf("Minimum moves = %lld\n", dp[n]);

    if (n == 8)
    {
        printf("For 8 disks, minimum moves = %lld\n", dp[8]);
        printf("Optimal split k = %d\n", split[8]);
    }

    return 0;
}
