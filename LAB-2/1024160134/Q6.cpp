#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, terms;
    Term data[100]; // adjust size if needed
};

// Function to read sparse matrix
void readMatrix(SparseMatrix &m) {
    cout << "Enter rows, cols, number of non-zero terms: ";
    cin >> m.rows >> m.cols >> m.terms;

    cout << "Enter row, col, value for each non-zero term:\n";
    for (int i = 0; i < m.terms; i++) {
        cin >> m.data[i].row >> m.data[i].col >> m.data[i].val;
    }
}

// Function to print sparse matrix
void printMatrix(SparseMatrix m) {
    cout << "Row Col Val\n";
    for (int i = 0; i < m.terms; i++) {
        cout << m.data[i].row << "   " << m.data[i].col << "   " << m.data[i].val << "\n";
    }
}

// (a) Transpose
SparseMatrix transpose(SparseMatrix m) {
    SparseMatrix t;
    t.rows = m.cols;
    t.cols = m.rows;
    t.terms = m.terms;

    int k = 0;
    for (int c = 0; c < m.cols; c++) {
        for (int i = 0; i < m.terms; i++) {
            if (m.data[i].col == c) {
                t.data[k].row = m.data[i].col;
                t.data[k].col = m.data[i].row;
                t.data[k].val = m.data[i].val;
                k++;
            }
        }
    }
    return t;
}

// (b) Addition of two matrices
SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    SparseMatrix sum;
    if (a.rows != b.rows || a.cols != b.cols) {
        sum.terms = 0;
        cout << "Matrix dimensions do not match for addition!\n";
        return sum;
    }

    sum.rows = a.rows;
    sum.cols = a.cols;
    int i = 0, j = 0, k = 0;

    while (i < a.terms && j < b.terms) {
        if (a.data[i].row == b.data[j].row && a.data[i].col == b.data[j].col) {
            sum.data[k].row = a.data[i].row;
            sum.data[k].col = a.data[i].col;
            sum.data[k].val = a.data[i].val + b.data[j].val;
            if (sum.data[k].val != 0) k++;
            i++; j++;
        } else if ((a.data[i].row < b.data[j].row) ||
                   (a.data[i].row == b.data[j].row && a.data[i].col < b.data[j].col)) {
            sum.data[k++] = a.data[i++];
        } else {
            sum.data[k++] = b.data[j++];
        }
    }
    while (i < a.terms) sum.data[k++] = a.data[i++];
    while (j < b.terms) sum.data[k++] = b.data[j++];

    sum.terms = k;
    return sum;
}

// (c) Multiplication
SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    SparseMatrix prod;
    if (a.cols != b.rows) {
        prod.terms = 0;
        cout << "Matrix dimensions do not match for multiplication!\n";
        return prod;
    }

    prod.rows = a.rows;
    prod.cols = b.cols;
    prod.terms = 0;

    // For multiplication, take transpose of B for easier column access
    SparseMatrix bT = transpose(b);

    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < bT.rows; j++) {
            int sum = 0;
            for (int p = 0; p < a.terms; p++) {
                if (a.data[p].row == i) {
                    for (int q = 0; q < bT.terms; q++) {
                        if (bT.data[q].row == j && a.data[p].col == bT.data[q].col) {
                            sum += a.data[p].val * bT.data[q].val;
                        }
                    }
                }
            }
            if (sum != 0) {
                prod.data[prod.terms].row = i;
                prod.data[prod.terms].col = j;
                prod.data[prod.terms].val = sum;
                prod.terms++;
            }
        }
    }
    return prod;
}

// ---------- Main Function ----------
int main() {
    SparseMatrix A, B;
    cout << "Enter first sparse matrix:\n";
    readMatrix(A);
    cout << "Enter second sparse matrix:\n";
    readMatrix(B);

    cout << "\nFirst Matrix:\n"; printMatrix(A);
    cout << "\nSecond Matrix:\n"; printMatrix(B);

    cout << "\nTranspose of First Matrix:\n";
    SparseMatrix AT = transpose(A);
    printMatrix(AT);

    cout << "\nAddition (A+B):\n";
    SparseMatrix C = add(A, B);
    printMatrix(C);

    cout << "\nMultiplication (A*B):\n";
    SparseMatrix D = multiply(A, B);
    printMatrix(D);

    return 0;
}