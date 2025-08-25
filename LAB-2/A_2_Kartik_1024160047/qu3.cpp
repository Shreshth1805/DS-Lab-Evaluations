#include <iostream>      // a) LINEAR TIME
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    return 0;
}





          


int findMissingBinary(int arr[], int n) {                // BINARY SEARCH
    int low = 0, high = n - 2; // array size = n-1

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            // left part is correct, missing on right
            low = mid + 1;
        } else {
            // missing is on left
            high = mid - 1;
        }
    }
    return low + 1; // low points to missing number
}

int main() {
    int arr[] = {1, 2, 3, 5, 6}; // n = 6
    int n = 6;

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;
    return 0;
}
