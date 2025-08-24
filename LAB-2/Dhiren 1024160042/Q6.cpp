#include <iostream>
using namespace std;
struct Term {
    int row, col, val;
};
void readSparse(Term mat[], int &n) {
    cout << "Enter rows, cols, and number of non-zero elements: ";
    cin >> mat[0].row >> mat[0].col >> mat[0].val;
    n = mat[0].val;
    cout << "Enter row col value for each non-zero element:\n";
    for (int i = 1; i <= n; i++) {
        cin >> mat[i].row >> mat[i].col >> mat[i].val;
    }
}
void printSparse(Term mat[]) {
    cout << mat[0].row << " " << mat[0].col << " " << mat[0].val << "\n";
    for (int i = 1; i <= mat[0].val; i++) {
        cout << mat[i].row << " " << mat[i].col << " " << mat[i].val << "\n";
    }
}
void transpose(Term a[], Term b[]) {
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = a[0].val;
    int k = 1;
    for (int col = 0; col < a[0].col; col++) {
        for (int i = 1; i <= a[0].val; i++) {
            if (a[i].col == col) {
                b[k].row = a[i].col;
                b[k].col = a[i].row;
                b[k].val = a[i].val;
                k++;
            }
        }
    }
}
void addSparse(Term A[], Term B[], Term C[]) {
    if (A[0].row != B[0].row || A[0].col != B[0].col) {
        cout << "Matrix dimensions must match for addition.\n";
        C[0].val = 0;
        return;
    }
    C[0].row = A[0].row;
    C[0].col = A[0].col;
    int i = 1, j = 1, k = 1;
    while (i <= A[0].val && j <= B[0].val) {
        if (A[i].row == B[j].row && A[i].col == B[j].col) {
            int sum = A[i].val + B[j].val;
            if (sum != 0) {
                C[k++] = {A[i].row, A[i].col, sum};
            }
            i++; j++;
        }
        else if (A[i].row < B[j].row || 
                (A[i].row == B[j].row && A[i].col < B[j].col)) {
            C[k++] = A[i++];
        }
        else {
            C[k++] = B[j++];
        }
    }
    while (i <= A[0].val) C[k++] = A[i++];
    while (j <= B[0].val) C[k++] = B[j++];
    C[0].val = k - 1;
}
void multiplySparse(Term A[], Term B[], Term C[]) {
    if (A[0].col != B[0].row) {
        cout << "Matrix dimensions incompatible for multiplication.\n";
        C[0].val = 0;
        return;
    }
    Term BT[100];
    transpose(B, BT);
    C[0].row = A[0].row;
    C[0].col = B[0].col;
    int k = 1;
    for (int r = 0; r < A[0].row; r++) {
        for (int c = 0; c < B[0].col; c++) {
            int sum = 0;
            for (int i = 1; i <= A[0].val; i++) {
                if (A[i].row == r) {
                    for (int j = 1; j <= BT[0].val; j++) {
                        if (BT[j].row == c && BT[j].col == A[i].col) {
                            sum += A[i].val * BT[j].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                C[k++] = {r, c, sum};
            }
        }
    }
    C[0].val = k - 1;
}
int main() {
    Term A[100], B[100], T[100], SUM[100], PROD[100];
    int nA, nB;

    cout << "Enter first sparse matrix:\n";
    readSparse(A, nA);

    cout << "Enter second sparse matrix:\n";
    readSparse(B, nB);

    cout << "\nTranspose of first matrix:\n";
    transpose(A, T);
    printSparse(T);

    cout << "\nAddition of matrices:\n";
    addSparse(A, B, SUM);
    if (SUM[0].val > 0) printSparse(SUM);

    cout << "\nMultiplication of matrices:\n";
    multiplySparse(A, B, PROD);
    if (PROD[0].val > 0) printSparse(PROD);

    return 0;
}
