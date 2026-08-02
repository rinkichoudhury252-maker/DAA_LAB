#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/**
 * Simulates coin tosses and returns the probability of getting HEAD.
 * @param tosses: Number of tosses to simulate.
 * @param head_prob: Probability of HEAD (0.0 to 1.0).
 * @return: Estimated probability of HEAD from simulation.
 */
double simulate_coin_toss(long tosses, double head_prob) {
    if (tosses <= 0 || head_prob < 0.0 || head_prob > 1.0) {
        fprintf(stderr, "Invalid parameters for simulation.\n");
        return -1.0;
    }

    long heads_count = 0;

    for (long i = 0; i < tosses; i++) {
        // Generate a random number between 0 and 1
        double r = (double)rand() / RAND_MAX;
        if (r < head_prob) {
            heads_count++;
        }
    }

    return (double)heads_count / tosses;
}

int main() {
    srand((unsigned int)time(NULL)); // Seed RNG

    long tosses;
    double biased_prob;

    printf("Enter number of tosses to simulate: ");
    if (scanf("%ld", &tosses) != 1 || tosses <= 0) {
        printf("Invalid input. Please enter a positive integer.\n");
        return 1;
    }

    printf("Enter probability of HEAD for biased coin (0.0 to 1.0): ");
    if (scanf("%lf", &biased_prob) != 1 || biased_prob < 0.0 || biased_prob > 1.0) {
        printf("Invalid probability. Must be between 0.0 and 1.0.\n");
        return 1;
    }

    // Fair coin simulation (p = 0.5)
    double fair_result = simulate_coin_toss(tosses, 0.5);
    if (fair_result < 0) return 1;

    // Biased coin simulation
    double biased_result = simulate_coin_toss(tosses, biased_prob);
    if (biased_result < 0) return 1;

    printf("\n--- Simulation Results ---\n");
    printf("Fair Coin (p=0.5): Estimated HEAD probability = %.5f\n", fair_result);
    printf("Biased Coin (p=%.2f): Estimated HEAD probability = %.5f\n", biased_prob, biased_result);

    printf("\nObservation: As tosses increase, the estimated probability approaches the true probability.\n");

    return 0;
}
