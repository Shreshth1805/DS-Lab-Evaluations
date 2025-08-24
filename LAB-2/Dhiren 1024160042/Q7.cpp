#include <iostream>
using namespace std;

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    
    int j = mid + 1;  
    int k = left;   
    long long inv_count = 0;
    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            inv_count += (mid - i + 1);
        }
    }
    while (i <= mid) {
        temp[k++] = arr[i++];
    }
    while (j <= right) {
        temp[k++] = arr[j++];
    }
    for (i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    return inv_count;
}
long long mergeSortAndCount(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = (left + right) / 2;
        inv_count += mergeSortAndCount(arr, temp, left, mid);     
        inv_count += mergeSortAndCount(arr, temp, mid + 1, right); 
        inv_count += mergeAndCount(arr, temp, left, mid, right);  
    }
    return inv_count;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[1000];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int temp[1000];
    long long inversionCount = mergeSortAndCount(arr, temp, 0, n - 1);

    cout << "Number of inversions: " << inversionCount << endl;
    return 0;
}
