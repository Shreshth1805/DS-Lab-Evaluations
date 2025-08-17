#include <iostream>
using namespace std;

int countInversions(int arr[], int n) {
    int inv_count = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                inv_count++;
            }
        }
    }
    return inv_count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    int inv_count = countInversions(arr, n);

    cout << "Number of inversions : " << inv_count << endl;

    return 0;
}
