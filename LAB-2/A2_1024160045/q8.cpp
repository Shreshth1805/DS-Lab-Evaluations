#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_set<int> distinctElements;

    for (int x : arr) {
        distinctElements.insert(x);
    }

    cout << "Total number of distinct elements = " 
         << distinctElements.size() << endl;

    return 0;
}
