#include <iostream>
using namespace std;

int main() {
    int A[10][15], T[10][20];
    int m, n;

    cout << "Enter rows and cols of matrix: ";
    cin >> m >> n;

    cout << "Enter elements of matrix: ";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    // Transpose
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            T[j][i] = A[i][j];
        }
    }

    // Result
    cout << "Transpose Matrix: \n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << T[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
