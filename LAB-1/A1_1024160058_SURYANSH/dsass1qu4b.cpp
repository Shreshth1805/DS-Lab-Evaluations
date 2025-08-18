#include <iostream>
using namespace std;

int main() {
    int A[10][15], B[10][20], C[10][30];
    int m, n, p, q;

    cout << "Enter rows and cols of first matrix (m n): ";
    cin >> m >> n;
    cout << "Enter rows and cols of second matrix (p q): ";
    cin >> p >> q;

    if (n != p) {
        cout << "Matrix multiplication not possible (n != p)" << endl;
        return 0;
    }

    cout << "Enter elements of first matrix: ";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of second matrix: ";
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            cin >> B[i][j];

    // Multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            C[i][j] = 0;
            for (int k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Result
    cout << "Resultant Matrix: \n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < q; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
