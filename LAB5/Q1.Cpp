#include <iostream>
using namespace std;

// Partition the array around a pivot
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

// Quickselect to find the k-th smallest element
int quickSelect(int arr[], int low, int high, int k)
{
    if (low <= high)
    {
        int pivotIndex = partition(arr, low, high);

        if (pivotIndex == k)
            return arr[pivotIndex];

        else if (k < pivotIndex)
            return quickSelect(arr, low, pivotIndex - 1, k);

        else
            return quickSelect(arr, pivotIndex + 1, high, k);
    }

    return -1;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    double median;

    if (n % 2 == 1)
    {
        // For odd N: find the middle element
        median = quickSelect(arr, 0, n - 1, n / 2);
    }
    else
    {
        // For even N: find the two middle elements
        int left = quickSelect(arr, 0, n - 1, n / 2 - 1);
        int right = quickSelect(arr, 0, n - 1, n / 2);

        median = (left + right) / 2.0;
    }

    cout << "Median = " << median << endl;

    return 0;
}