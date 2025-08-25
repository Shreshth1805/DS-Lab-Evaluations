// // Linear time
// #include <iostream>
// using namespace std;

// int findMissingLinear(int arr[], int n) {
//     for (int i = 0; i < n - 1; i++) {
//         if (arr[i] != i + 1) {
//             return i + 1;
//         }
//     }
//     return n;
// }

// int main() {
//     int arr[] = {1, 2, 3, 4, 6, 7, 8}; // Missing number = 5
//     int n = 8;

//     cout << "Missing Number (Linear Search): " << findMissingLinear(arr, n) << endl;

//     return 0;
// }



//binary search
#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2; // bec array size is n-1
    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 4, 6, 7, 8}; // Missing number is 5
    int n = 8;

    cout << "Missing Number (Binary Search): " << findMissingBinary(arr, n) << endl;

    return 0;
}
