#include <iostream>
using namespace std;

/* Count distinct elements in an array */
int countDistinct(int arr[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        bool isDistinct = true;
        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct) count++;
    }

    return count;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Total distinct elements: " << countDistinct(arr, n) << endl;

    return 0;
}
