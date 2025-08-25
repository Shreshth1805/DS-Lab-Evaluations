#include <iostream>
using namespace std;

/* Store Diagonal Matrix efficiently */
void diagonalMatrix(int n) {
    int arr[n]; // store only diagonal elements
    cout << "Enter diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << arr[i] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

/* Store Tri-diagonal Matrix efficiently */
void tridiagonalMatrix(int n) {
    int arr[3*n - 2]; // main, upper, lower diagonals
    cout << "Enter elements of tridiagonal matrix rowwise (" << 3*n - 2 << " values): ";
    for (int i = 0; i < 3*n - 2; i++) cin >> arr[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0, k = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
        if (i - j == -1 || i - j == 0 || i - j == 1) {
            cout << arr[k] << " ";
            k++;
        } else {
            cout << "0 ";
        }
    }
    cout << endl;
}

}

/* Store Lower Triangular Matrix efficiently */
void lowerTriangularMatrix(int n) {
    int arr[n*(n+1)/2]; // only store lower elements
    cout << "Enter elements of lower triangular matrix (" << n*(n+1)/2 << " values): ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> arr[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << arr[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

/* Store Upper Triangular Matrix efficiently */
void upperTriangularMatrix(int n) {
    int arr[n*(n+1)/2]; // only store upper elements
    cout << "Enter elements of upper triangular matrix (" << n*(n+1)/2 << " values): ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> arr[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) cout << arr[k++] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
}

/* Store Symmetric Matrix efficiently */
void symmetricMatrix(int n) {
    int arr[n*(n+1)/2]; // store lower triangle
    cout << "Enter elements of symmetric matrix (" << n*(n+1)/2 << " values): ";
    for (int i = 0; i < n*(n+1)/2; i++) cin >> arr[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << arr[k++] << " ";
            else cout << arr[j*(j+1)/2 + i] << " "; // mirror from lower triangle
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter size of matrix (n): ";
    cin >> n;

    cout << "\nDiagonal Matrix -\n";
    diagonalMatrix(n);

    cout << "\nTri-diagonal Matrix -\n";
    tridiagonalMatrix(n);

    cout << "\nLower Triangular Matrix -\n";
    lowerTriangularMatrix(n);

    cout << "\nUpper Triangular Matrix -\n";
    upperTriangularMatrix(n);

    cout << "\nSymmetric Matrix -\n";
    symmetricMatrix(n);

    return 0;
}
