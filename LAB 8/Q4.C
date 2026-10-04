#include <stdio.h>

int main() {
    int A[] = {10, 22, 9, 33, 21, 50, 41, 60};
    int n = sizeof(A) / sizeof(A[0]);

    int dp[n];

    int maxLength = 1;

    for (int i = 0; i < n; i++)
        dp[i] = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {

            if (A[j] < A[i] && dp[j] + 1 > dp[i])
                dp[i] = dp[j] + 1;
        }

        if (dp[i] > maxLength)
            maxLength = dp[i];
    }

    printf("Length of LIS = %d\n", maxLength);

    return 0;
}