#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function to heapify the array
void heapify(int arr[], int n, int i)
{
    int largest = i;          // Assume root is largest
    int left = 2 * i + 1;     // Left child
    int right = 2 * i + 2;    // Right child

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than current largest
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and heapify again
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n)
{
    // Build Max Heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--)
    {
        // Move current largest to the end
        swap(arr[0], arr[i]);

        // Heapify the reduced heap
        heapify(arr, i, 0);
    }
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    // Initialize random number generator
    srand(time(0));

    // Create and open file
    ofstream outFile("numbers.txt");

    // Generate random numbers and store them in file
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
        outFile << arr[i] << " ";
    }

    outFile.close();

    // Open file for reading
    ifstream inFile("numbers.txt");

    // Read numbers from file
    for (int i = 0; i < n; i++)
    {
        inFile >> arr[i]  ;
    }

    inFile.close();

    // Display elements before sorting
    cout << "\nElements before sorting:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    // Apply Heap Sort
    heapSort(arr, n);

    // Display elements after sorting
    cout << "\n\nElements after Heap Sort:\n";

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}