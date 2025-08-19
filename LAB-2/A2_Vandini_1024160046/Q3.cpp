#include <iostream>
using namespace std;

int missingNum(int arr[], int size) {
    int expectedSum = (size + 1) * (size + 2) / 2; 
    int actualSum = 0;
    for (int i = 0; i < size; i++) {
        actualSum += arr[i];
    }
    return expectedSum - actualSum;
}
int missingNumBS(int arr[], int size) {
    int left = 0;
    int right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] != mid + 1) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return left + 1;
}
int main() {
    int arr[] = {1, 2, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    int missingNumber = missingNum(arr, size);
    int missingNumberBinary = missingNumBS(arr, size);
    cout << "Missing number is: " << missingNumber << endl;
    cout << "Missing number using binary search is: " << missingNumberBinary << endl;
    return 0;
}