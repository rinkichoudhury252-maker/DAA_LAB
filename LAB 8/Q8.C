#include <stdio.h>
#include <float.h>

#define MAX 20

int main() {

    int n = 3;

    double p[] = {0, 0.15, 0.10, 0.05};
    double q[] = {0.05, 0.10, 0.05, 0.05};

    double e[MAX][MAX];
    double w[MAX][MAX];

    int root[MAX][MAX];

    for (int i = 1; i <= n + 1; i++) {

        e[i][i - 1] = q[i - 1];
        w[i][i - 1] = q[i - 1];
    }

    for (int length = 1; length <= n; length++) {

        for (int i = 1; i <= n - length + 1; i++) {

            int j = i + length - 1;

            e[i][j] = DBL_MAX;

            w[i][j] =
                w[i][j - 1] +
                p[j] +
                q[j];

            for (int r = i; r <= j; r++) {

                double cost =
                    e[i][r - 1] +
                    e[r + 1][j] +
                    w[i][j];

                if (cost < e[i][j]) {

                    e[i][j] = cost;
                    root[i][j] = r;
                }
            }
        }
    }

    printf("Minimum Expected Search Cost = %.2lf\n",
           e[1][n]);

    printf("Root of optimal BST = K%d\n",
           root[1][n]);

    return 0;
}