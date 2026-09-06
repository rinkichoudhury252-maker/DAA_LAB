#include <iostream>
#include <vector>
using namespace std;

long long totalCost = 0;
int reversalCount = 0;

// Reverse elements from l to r
void reversePart(vector<int>& a, int l, int r)
{
    if (l >= r)
        return;

    totalCost += (r - l + 1);
    reversalCount++;

    while (l < r)
    {
        swap(a[l], a[r]);
        l++;
        r--;
    }
}

// Rotate [l...m] and [m+1...r]
// [A B] -> [B A]
void rotateBlocks(vector<int>& a, int l, int m, int r)
{
    if (l > m || m >= r)
        return;

    reversePart(a, l, m);
    reversePart(a, m + 1, r);
    reversePart(a, l, r);
}

// Stable partition
int stablePartition(vector<int>& a, int l, int r, int pivot)
{
    if (l > r)
        return l;

    if (l == r)
    {
        if (a[l] <= pivot)
            return l + 1;
        return l;
    }

    int mid = (l + r) / 2;

    int leftBoundary =
        stablePartition(a, l, mid, pivot);

    int rightBoundary =
        stablePartition(a, mid + 1, r, pivot);

    // [small | large] [small | large]
    if (leftBoundary <= mid &&
        mid + 1 < rightBoundary)
    {
        rotateBlocks(
            a,
            leftBoundary,
            mid,
            rightBoundary - 1
        );

        leftBoundary +=
            rightBoundary - (mid + 1);
    }

    return leftBoundary;
}

// Divide and conquer sorting
void sortPermutation(vector<int>& a,
                     int l,
                     int r,
                     int low,
                     int high)
{
    if (l >= r || low >= high)
        return;

    int pivot = (low + high) / 2;

    int boundary =
        stablePartition(a, l, r, pivot);

    sortPermutation(
        a, l, boundary - 1,
        low, pivot
    );

    sortPermutation(
        a, boundary, r,
        pivot + 1, high
    );
}

int main()
{
    int n;

    cout << "Enter n: ";
    cin >> n;

    vector<int> a(n);

    cout << "Enter permutation of 1 to "
         << n << ":\n";

    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "\nOriginal permutation:\n";

    for (int x : a)
        cout << x << " ";

    sortPermutation(a, 0, n - 1, 1, n);

    cout << "\n\nSorted permutation:\n";

    for (int x : a)
        cout << x << " ";

    cout << "\n\nNumber of reversals = "
         << reversalCount << endl;

    cout << "Total reversal cost = "
         << totalCost << endl;

    return 0;
}