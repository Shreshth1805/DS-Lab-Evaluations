#include<iostream>
using namespace std;

int missing(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        if(arr[i] != arr[i+1] - 1) {
            return arr[i] + 1; 
        }
    }
    return arr[n-1] + 1; 
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int miss = missing(arr, n);
    cout << "The missing number is " << miss << endl;

    return 0;
}
