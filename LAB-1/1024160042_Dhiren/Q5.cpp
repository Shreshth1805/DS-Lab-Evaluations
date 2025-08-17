#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    int matrix[10][10];

    cout << "Enter matrix elements:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> matrix[i][j];
        }
    }

    cout << "\nSum of each row:\n";
    for (int i = 0; i < rows; i++) {
        int sumRow = 0;
        for (int j = 0; j < cols; j++) {
            sumRow += matrix[i][j];
        }
        cout << "Row " << i + 1 << ": " << sumRow << endl;
    }

    cout << "\nSum of each column:\n";
    for (int j = 0; j < cols; j++) {
        int sumCol = 0;
        for (int i = 0; i < rows; i++) {
            sumCol += matrix[i][j];
        }
        cout << "Column " << j + 1 << ": " << sumCol << endl;
    }

    return 0;
}
