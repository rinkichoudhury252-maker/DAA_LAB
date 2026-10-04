#include <stdio.h>

int main() {

    int n = 8;

    int price[] = {
        0, 5, 8, 9, 10, 17, 17, 20, 24
    };

    int dp[n + 1];
    int cut[n + 1];

    dp[0] = 0;

    for (int i = 1; i <= n; i++) {

        dp[i] = -1;

        for (int j = 1; j <= i; j++) {

            if (price[j] + dp[i - j] > dp[i]) {

                dp[i] = price[j] + dp[i - j];

                cut[i] = j;
            }
        }
    }

    printf("Maximum Revenue = %d\n", dp[n]);

    printf("Optimal pieces: ");

    int length = n;

    while (length > 0) {

        printf("%d ", cut[length]);

        length -= cut[length];
    }

    printf("\n");

    return 0;
}