#include <iostream>
using namespace std;

int main() {
    int m, n, p;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> m >> n;

    cout << "Enter columns of Matrix B: ";
    cin >> p;

    // Matrix A (m x n)
    int A[m][n];
    cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    // Matrix B (n x p)
    int B[n][p];
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            cin >> B[i][j];
        }
    }

    // Result matrix C (m x p)
    int C[m][p];
    // Initialize C to 0
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C[i][j] = 0;
        }
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<p;k++){
                C[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    cout << "Resultant Matrix C (m x p):\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}