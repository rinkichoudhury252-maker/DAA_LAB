#include <stdio.h>
#include <limits.h>

int minCoins(int coins[], int n, int V) {
    int dp[V + 1];

    dp[0] = 0;

    for (int i = 1; i <= V; i++)
        dp[i] = INT_MAX;

    for (int i = 1; i <= V; i++) {
        for (int j = 0; j < n; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                int value = dp[i - coins[j]] + 1;

                if (value < dp[i])
                    dp[i] = value;
            }
        }
    }

    return dp[V] == INT_MAX ? -1 : dp[V];
}

int main() {
    int coins[] = {1, 2, 5};
    int n = 3;
    int V = 11;

    int ans = minCoins(coins, n, V);

    printf("Minimum number of coins = %d\n", ans);

    return 0;
}