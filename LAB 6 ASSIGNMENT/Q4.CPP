#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter N: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter dimensions:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int dp[n][n];

    // Cost of multiplying one matrix is 0
    for (int i = 1; i < n; i++)
        dp[i][i] = 0;

    // Chain length
    for (int length = 2; length < n; length++) {

        for (int i = 1; i < n - length + 1; i++) {

            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + arr[i - 1] * arr[k] * arr[j];

                if (cost < dp[i][j])
                    dp[i][j] = cost;
            }
        }
    }

    printf("Minimum number of scalar multiplications = %d\n",
           dp[1][n - 1]);

    return 0;
}