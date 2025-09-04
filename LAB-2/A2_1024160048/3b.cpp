#include<iostream>
using namespace std;
int binarysearch(int arr[], int size){
    int left = 0, right = size-1;
    while(left <= right){
        int mid = left + (right - left) / 2;    
        if(arr[mid] == mid+1) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    return left + 1;
}
int main() {
    int n, size;
    cout<< "Enter numbers size (n): ";
    cin >> n;
    size = n-1;

    int arr[size];
    cout << "Enter elements: ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }
    cout << "Missing number (Binary Search): " << binarysearch(arr, size) << endl;
}