#include <iostream>
#include <set>
using namespace std;
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    set<int> distinctElements;
    for (int i = 0; i < n; i++) {
        distinctElements.insert(arr[i]);
    }
    cout << "Total number of distinct elements: " << distinctElements.size() << endl;
    return 0;
}
