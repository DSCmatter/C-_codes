#include <iostream>
#include <climits>
using namespace std;

int main() {
    int n;

    // Get the number of elements from the user
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    if (n <= 1) {
        cerr << "Please enter a valid number of elements greater than 1." << endl;
        return 1;
    }

    int* arr = new int[n];  // Dynamic allocation for the array

    // Input: Read array elements from the user
    cout << "Enter " << n << " integer elements:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
    }

    // Initialize variables for maximum and minimum difference
    int maxDiff = INT_MIN;
    int minDiff = INT_MAX;
    int maxDiffIndex1, maxDiffIndex2, minDiffIndex1, minDiffIndex2;

    // Find pair of elements with maximum and minimum difference
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int diff = abs(arr[i] - arr[j]);

            // Update maximum difference
            if (diff > maxDiff) {
                maxDiff = diff;
                maxDiffIndex1 = i;
                maxDiffIndex2 = j;
            }

            // Update minimum difference
            if (diff < minDiff) {
                minDiff = diff;
                minDiffIndex1 = i;
                minDiffIndex2 = j;
            }
        }
    }

    // Display the pair with maximum difference
    cout << "Pair with maximum difference: (" << arr[maxDiffIndex1] << ", " << arr[maxDiffIndex2] << ")"
              << " with difference " << maxDiff << endl;

    // Display the pair with minimum difference
    cout << "Pair with minimum difference: (" << arr[minDiffIndex1] << ", " << arr[minDiffIndex2] << ")"
              << " with difference " << minDiff << endl;

    // Deallocate the dynamic memory
    delete[] arr;

    return 0;
}
