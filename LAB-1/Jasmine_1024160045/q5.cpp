#include <iostream>
using namespace std;

int main() {
    int matrix[10][10];
    int rowSum[10], colSum[10];
    int rows, cols;

    cout << "Enter number of rows and columns: ";
    cin >> rows >> cols;

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cin >> matrix[i][j];

    for (int i = 0; i < rows; ++i)
        rowSum[i] = 0;
    for (int j = 0; j < cols; ++j)
        colSum[j] = 0;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            rowSum[i] += matrix[i][j];
            colSum[j] += matrix[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; ++i)
        cout << "Row " << i + 1 << ": " << rowSum[i] << endl;

    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; ++j)
        cout << "Column " << j + 1 << ": " << colSum[j] << endl;

    return 0;
}
