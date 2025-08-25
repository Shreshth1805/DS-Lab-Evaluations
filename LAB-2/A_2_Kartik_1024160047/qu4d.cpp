#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.ignore();

    string arr[100];
    cout << "Enter strings: \n";
    for (int i = 0; i < n; i++) {
        getline(cin, arr[i]);
    }

    sort(arr, arr + n);

    cout << "Strings in alphabetical order:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}
