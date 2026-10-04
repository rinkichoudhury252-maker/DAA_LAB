#include <stdio.h>

int main() {
    int A[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(A) / sizeof(A[0]);

    int dp[n];
    int maxSum = 0;

    for (int i = 0; i < n; i++)
        dp[i] = A[i];

    for (int i = 1; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (A[j] < A[i] &&
                dp[i] < dp[j] + A[i]) {

                dp[i] = dp[j] + A[i];
            }
        }

        if (dp[i] > maxSum)
            maxSum = dp[i];
    }

    printf("Maximum sum = %d\n", maxSum);

    return 0;
}