#include <iostream>
using namespace std;

int countDistinct(int arr[], int n) {
    int distinctCount = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }

        if (isDistinct) {
            distinctCount++;
        }
    }
    return distinctCount;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Total number of distinct elements: " 
         << countDistinct(arr, n) << endl;

    return 0;
}
