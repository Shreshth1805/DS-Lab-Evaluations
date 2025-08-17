#include <iostream>
using namespace std;
struct Term {
    int row, col, val;
};
class SparseMatrix {
    int rows, cols, terms;
    Term *data;
public:
    SparseMatrix(int r = 0, int c = 0, int t = 0) {
        rows = r;
        cols = c;
        terms = t;
        data = new Term[terms];
    }
    void read() {
        cout << "Enter matrix in triplet form (row col value):\n";
        for (int i = 0; i < terms; i++) {
            cin >> data[i].row >> data[i].col >> data[i].val;
        }
    }
    void display() {
        cout << "Row Col Val\n";
        for (int i = 0; i < terms; i++) {
            cout << data[i].row << " " << data[i].col << " " << data[i].val << endl;
        }
    }
    SparseMatrix transpose() {
        SparseMatrix trans(cols, rows, terms);
        int k = 0;
        for (int c = 0; c < cols; c++) {
            for (int i = 0; i < terms; i++) {
                if (data[i].col == c) {
                    trans.data[k].row = data[i].col;
                    trans.data[k].col = data[i].row;
                    trans.data[k].val = data[i].val;
                    k++;
                }
            }
        }
        return trans;
    }
    SparseMatrix add(SparseMatrix b) {
        if (rows != b.rows || cols != b.cols) {
            cout << "Addition not possible\n";
            return SparseMatrix();
        }
        SparseMatrix sum(rows, cols, terms + b.terms);
        int i = 0, j = 0, k = 0;

        while (i < terms && j < b.terms) {
            if (data[i].row == b.data[j].row && data[i].col == b.data[j].col) {
                int val = data[i].val + b.data[j].val;
                if (val != 0) {
                    sum.data[k++] = {data[i].row, data[i].col, val};
                }
                i++; j++;
            }
            else if ((data[i].row < b.data[j].row) || 
                     (data[i].row == b.data[j].row && data[i].col < b.data[j].col)) {
                sum.data[k++] = data[i++];
            }
            else {
                sum.data[k++] = b.data[j++];
            }
        }
        while (i < terms) sum.data[k++] = data[i++];
        while (j < b.terms) sum.data[k++] = b.data[j++];
        sum.terms = k;
        return sum;
    }
    SparseMatrix multiply(SparseMatrix b) {
        if (cols != b.rows) {
            cout << "Multiplication not possible\n";
            return SparseMatrix();
        }
        SparseMatrix bt = b.transpose(); 
        SparseMatrix result(rows, b.cols, rows * b.cols); 
        int k = 0;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < bt.rows; j++) {
                int sum = 0;
                for (int p = 0; p < terms; p++) {
                    if (data[p].row == i) {
                        for (int q = 0; q < bt.terms; q++) {
                            if (bt.data[q].row == j && data[p].col == bt.data[q].col) {
                                sum += data[p].val * bt.data[q].val;
                            }
                        }
                    }
                }
                if (sum != 0) {
                    result.data[k++] = {i, j, sum};
                }
            }
        }
        result.terms = k;
        return result;
    }
};
int main() {
    int r1, c1, t1, r2, c2, t2;
    cout << "Enter rows, cols, and number of non-zero terms for Matrix A: ";
    cin >> r1 >> c1 >> t1;
    SparseMatrix A(r1, c1, t1);
    A.read();
    cout << "Matrix A in triplet form:\n";
    A.display();
    cout << "\nTranspose of A:\n";
    SparseMatrix AT = A.transpose();
    AT.display();
    cout << "\nEnter rows, cols, and number of non-zero terms for Matrix B: ";
    cin >> r2 >> c2 >> t2;
    SparseMatrix B(r2, c2, t2);
    B.read();
    cout << "Matrix B in triplet form:\n";
    B.display();
    cout << "\nAddition (A + B):\n";
    SparseMatrix C = A.add(B);
    C.display();
    cout << "\nMultiplication (A * B):\n";
    SparseMatrix D = A.multiply(B);
    D.display();
    return 0;
}
