#include <iostream>
using namespace std;

// Tabulation (Bottom-Up DP)
int fibonacci(int n) {
    if (n <= 1) return n;

    int dp[n + 1];
    dp[0] = 0;   // base case
    dp[1] = 1;   // base case

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // recurrence
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << fibonacci(n) << endl;

    // Print the full series up to n
    cout << "Series: ";
    int a = 0, b = 1;
    for (int i = 0; i <= n; i++) {
        cout << a;
        if (i < n) cout << ", ";
        int temp = a + b;
        a = b;
        b = temp;
    }
    cout << endl;

    return 0;
}   