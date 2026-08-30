#include <iostream>
using namespace std;

// Partition the array
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);

    return i + 1;
}

// Find kth smallest element
int quickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        // Pivot is the kth smallest element
        if (pivotIndex == k - 1)
            return arr[pivotIndex];

        // Search in left part
        else if (k - 1 < pivotIndex)
            return quickSelect(arr, low, pivotIndex - 1, k);

        // Search in right part
        else
            return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;
}

int main()
{
    int n, k;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter k: ";
    cin >> k;

    if (k < 1 || k > n)
    {
        cout << "Invalid value of k";
        return 0;
    }

    int result = quickSelect(arr, 0, n - 1, k);

    cout << "The " << k << "th smallest element is: "
         << result << endl;

    return 0;
}