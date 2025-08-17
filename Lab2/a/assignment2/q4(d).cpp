#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    string arr[] = {"banana", "apple", "orange", "grape"};
    int n = 4;
    sort(arr, arr + n);
    cout << "Sorted strings:\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << endl;
    return 0;
}

