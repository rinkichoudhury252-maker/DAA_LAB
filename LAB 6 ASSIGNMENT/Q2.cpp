#include <iostream>
#include <vector>
#include <algorithm>

int knapsack(int W, const std::vector<int>& weights, const std::vector<int>& profits, int n) {
    // 2D DP table initialized to 0
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(W + 1, 0));

    // Build the table in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                // Maximum of including or excluding the current item
                dp[i][w] = std::max(profits[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                // Item cannot be included
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][W];
}

int main() {
    int n, W;
    std::cout << "Enter number of items: ";
    std::cin >> n;
    
    std::vector<int> profits(n), weights(n);
    std::cout << "Enter profits of items: ";
    for (int i = 0; i < n; i++) std::cin >> profits[i];
    
    std::cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++) std::cin >> weights[i];
    
    std::cout << "Enter maximum weight capacity W: ";
    std::cin >> W;

    std::cout << "Maximum profit obtained: " << knapsack(W, weights, profits, n) << std::endl;
    return 0;
}