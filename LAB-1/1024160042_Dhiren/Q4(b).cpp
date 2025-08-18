#include <iostream>
using namespace std;

int main() {
    int rowsA, colsA, colsB;
    cout << "Enter rows and columns of first matrix (rowsA colsA): ";
    cin >> rowsA >> colsA;

    cout << "Enter rows and columns of second matrix (colsA colsB): ";
    int rowsB;
    cin >> rowsB >> colsB;

    if (colsA != rowsB) {
        cout << "Matrix multiplication is not possible!\n";
        return 0;
    }

    int matA[10][10], matB[10][10], result[10][10] = {0};

    cout << "Enter first matrix:\n";
    for (int i = 0; i < rowsA; i++)
        for (int j = 0; j < colsA; j++)
            cin >> matA[i][j];

    cout << "Enter second matrix:\n";
    for (int i = 0; i < rowsB; i++)
        for (int j = 0; j < colsB; j++)
            cin >> matB[i][j];

    // Matrix Multiplication
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++)
            cout << result[i][j] << " ";
        cout << endl;
    }

    return 0;
}
