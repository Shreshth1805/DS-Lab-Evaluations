#include <iostream>
using namespace std;

int main() {
    int m, p, n;
    cout << "Enter rows and cols of first matrix (m p): ";
    cin >> m >> p;
    cout << "Enter rows and cols of second matrix (p n): ";
    int p2;
    cin >> p2 >> n;

    if (p != p2) {
        cout << "Matrix multiplication not possible! (Dimension mismatch)\n";
        return 0;
    }

    int A[10][10], B[10][10], C[10][10] = {0};

    cout << "Enter first matrix:\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < p; j++)
            cin >> A[i][j];

    cout << "Enter second matrix:\n";
    for (int i = 0; i < p2; i++)
        for (int j = 0; j < n; j++)
            cin >> B[i][j];

    // Multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < p; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "Resultant Matrix:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            cout << C[i][j] << " ";
        cout << endl;
    }

    return 0;
}