#include <iostream>
using namespace std; 
void setDiagonal(int A[], int n, int i, int j, int x) {
    if (i == j) A[i - 1] = x;
}
int getDiagonal(int A[], int n, int i, int j) {
    if (i == j) return A[i - 1];
    else return 0;
}
void setTriDiagonal(int A[], int n, int i, int j, int x) {
    if (i - j == 1) A[i - 2] = x;                     
    else if (i - j == 0) A[n - 1 + i - 1] = x;        
    else if (i - j == -1) A[2 * n - 1 + i - 1] = x;   
}
int getTriDiagonal(int A[], int n, int i, int j) {
    if (i - j == 1) return A[i - 2];
    else if (i - j == 0) return A[n - 1 + i - 1];
    else if (i - j == -1) return A[2 * n - 1 + i - 1];
    else return 0;
}
void setLowerTriangular(int A[], int n, int i, int j, int x) {
    if (i >= j) A[i * (i - 1) / 2 + (j - 1)] = x;
}
int getLowerTriangular(int A[], int n, int i, int j) {
    if (i >= j) return A[i * (i - 1) / 2 + (j - 1)];
    else return 0;
}
void setUpperTriangular(int A[], int n, int i, int j, int x) {
    if (i <= j) A[(i - 1) * n - (i - 2) * (i - 1) / 2 + (j - i)] = x;
}
int getUpperTriangular(int A[], int n, int i, int j) {
    if (i <= j) return A[(i - 1) * n - (i - 2) * (i - 1) / 2 + (j - i)];
    else return 0;
}
void setSymmetric(int A[], int n, int i, int j, int x) {
    if (i >= j) A[i * (i - 1) / 2 + (j - 1)] = x;
    else A[j * (j - 1) / 2 + (i - 1)] = x;
}
int getSymmetric(int A[], int n, int i, int j) {
    if (i >= j) return A[i * (i - 1) / 2 + (j - 1)];
    else return A[j * (j - 1) / 2 + (i - 1)];
}
void display(void (*printFunc)(int[], int), int A[], int n) {
    printFunc(A, n);
}
void printDiagonal(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << getDiagonal(A, n, i, j) << " ";
        cout << "\n";
    }
}
void printTriDiagonal(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << getTriDiagonal(A, n, i, j) << " ";
        cout << "\n";
    }
}
void printLowerTriangular(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << getLowerTriangular(A, n, i, j) << " ";
        cout << "\n";
    }
}
void printUpperTriangular(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << getUpperTriangular(A, n, i, j) << " ";
        cout << "\n";
    }
}
void printSymmetric(int A[], int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << getSymmetric(A, n, i, j) << " ";
        cout << "\n";
    }
}
int main() {
    int n = 4;


    int diag[4] = {0};
    setDiagonal(diag, n, 1, 1, 5);
    setDiagonal(diag, n, 2, 2, 8);
    setDiagonal(diag, n, 3, 3, 3);
    setDiagonal(diag, n, 4, 4, 6);
    cout << "\nDiagonal Matrix:\n";
    printDiagonal(diag, n);


    int tri[3 * 4 - 2] = {0};
    setTriDiagonal(tri, n, 1, 1, 4);
    setTriDiagonal(tri, n, 1, 2, 5);
    setTriDiagonal(tri, n, 2, 1, 6);
    setTriDiagonal(tri, n, 2, 2, 7);
    setTriDiagonal(tri, n, 2, 3, 8);
    setTriDiagonal(tri, n, 3, 2, 9);
    setTriDiagonal(tri, n, 3, 3, 1);
    setTriDiagonal(tri, n, 3, 4, 2);
    setTriDiagonal(tri, n, 4, 3, 3);
    setTriDiagonal(tri, n, 4, 4, 4);
    cout << "\nTri-diagonal Matrix:\n";
    printTriDiagonal(tri, n);

 
    int lower[4 * (4 + 1) / 2] = {0};
    int val = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            setLowerTriangular(lower, n, i, j, val++);
    cout << "\nLower Triangular Matrix:\n";
    printLowerTriangular(lower, n);

  
    int upper[4 * (4 + 1) / 2] = {0};
    val = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            setUpperTriangular(upper, n, i, j, val++);
    cout << "\nUpper Triangular Matrix:\n";
    printUpperTriangular(upper, n);

    
    int sym[4 * (4 + 1) / 2] = {0};
    val = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            setSymmetric(sym, n, i, j, val++);
    cout << "\nSymmetric Matrix:\n";
    printSymmetric(sym, n);

    return 0;
}