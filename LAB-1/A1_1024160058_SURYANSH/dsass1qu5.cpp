#include <iostream>
using namespace std;

int main() {
    int arr[10][10], m, n;

    cout << "Enter number of rows: ";
    cin >> m;
    cout << "Enter number of columns: ";
    cin >> n;

    cout << "Enter elements of the matrix: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    // Row sums
    cout << "\nSum of each row:\n";
    for (int i = 0; i < m; i++) {
        int rowSum = 0;
        for (int j = 0; j < n; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << " = " << rowSum << endl;
    }

    // Column sums
    cout << "\nSum of each column:\n";
    for (int j = 0; j < n; j++) {
        int colSum = 0;
        for (int i = 0; i < m; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}
