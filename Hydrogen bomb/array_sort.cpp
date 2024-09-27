#include <iostream>
#include <algorithm>  // Include the algorithm header for the sort function
using namespace std;

int main(){
    int arr[10] = {5,2,1,3,4,9,8,6,7,10};

    // Use the sort function to sort the array in ascending order
    sort(arr, arr + 10);

    // Output the ascending order of the array
    cout << "The ascending order of the array will be: ";
    for (int i = 0; i < 10; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
