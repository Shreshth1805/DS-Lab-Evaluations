#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0, end = n - 1;
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    cout << "Reversed Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n, arr[100];
    cout << "Enter size of array: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    reverseArray(arr, n);

    return 0;
}
