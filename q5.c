#include <stdio.h>

// Function to find the transition point using binary search
int findTransitionPoint(const int arr[], int n) {
    if (n <= 0) return -1; // Empty array case

    // If first element is 1, transition is at index 0
    if (arr[0] == 1) return 0;

    // If last element is 0, no transition exists
    if (arr[n - 1] == 0) return -1;

    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if this is the first 1
        if (arr[mid] == 1 && (mid == 0 || arr[mid - 1] == 0)) {
            return mid;
        }
        // If mid is 0, transition must be to the right
        else if (arr[mid] == 0) {
            low = mid + 1;
        }
        // If mid is 1 but not first, go left
        else {
            high = mid - 1;
        }
    }
    return -1; // No transition found
}

int main() {
    int arr[] = {0, 0, 0, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    int transitionIndex = findTransitionPoint(arr, n);

    if (transitionIndex != -1)
        printf("Transition point is at index: %d\n", transitionIndex);
    else
        printf("No transition point found.\n");

    return 0;
}
