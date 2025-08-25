#include <iostream>
using namespace std;


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2; 

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] < key) {
            low = mid + 1; 
        }
        else {
            high = mid - 1;
        }
    }
    return -1; 
}

int main() {
    int n, key, arr[100];

    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter elements of array (sorted): ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at position " << result + 1 << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}
