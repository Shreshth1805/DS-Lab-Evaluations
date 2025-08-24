#include <iostream>
using namespace std;

struct Element {
    int row;
    int col;
    int val;
};

/* Transpose of a Sparse Matrix */
void transpose(Element a[], Element b[]) {
    int n = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;

    int k = 1;
    for (int i = 0; i < a[0].col; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].val = a[j].val;
                k++;
            }
        }
    }
}

/* Addition of Two Sparse Matrices */
void add(Element a[], Element b[], Element c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible\n";
        return;
    }
    c[0].row = a[0].row;
    c[0].col = a[0].col;

    int i = 1, j = 1, k = 1;
    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        } else if (b[j].row < a[i].row || (a[i].row == b[j].row && b[j].col < a[i].col)) {
            c[k++] = b[j++];
        } else {
            c[k] = a[i];
            c[k].val = a[i].val + b[j].val;
            k++; i++; j++;
        }
    }
    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];
    c[0].val = k - 1;
}

/* Multiplication of Two Sparse Matrices */
void multiply(Element a[], Element b[], Element c[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible\n";
        return;
    }

    // Transpose b for easier column access
    Element bt[50];
    transpose(b, bt);

    c[0].row = a[0].row;
    c[0].col = b[0].col;
    int k = 1;

    for (int i = 1; i <= a[0].val;) {
        int r = a[i].row;
        int rowStart = i;
        while (i <= a[0].val && a[i].row == r) i++;

        for (int j = 1; j <= bt[0].val;) {
            int ccol = bt[j].row;
            int colStart = j;
            while (j <= bt[0].val && bt[j].row == ccol) j++;

            int p = rowStart, q = colStart, sum = 0;
            while (p < i && q < j) {
                if (a[p].col == bt[q].col) {
                    sum += a[p].val * bt[q].val;
                    p++; q++;
                } else if (a[p].col < bt[q].col) p++;
                else q++;
            }

            if (sum != 0) {
                c[k].row = r;
                c[k].col = ccol;
                c[k].val = sum;
                k++;
            }
        }
    }
    c[0].val = k - 1;
}

/* Print Sparse Matrix in Triplet Form */
void print(Element a[]) {
    for (int i = 0; i <= a[0].val; i++) {
        cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
    }
}

int main() {
    Element a[50], b[50], c[50];

    // First Matrix
    cout << "Enter rows, cols, non-zero count for A: ";
    cin >> a[0].row >> a[0].col >> a[0].val;
    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= a[0].val; i++)
        cin >> a[i].row >> a[i].col >> a[i].val;

    // Second Matrix
    cout << "Enter rows, cols, non-zero count for B: ";
    cin >> b[0].row >> b[0].col >> b[0].val;
    cout << "Enter triplets (row col value):\n";
    for (int i = 1; i <= b[0].val; i++)
        cin >> b[i].row >> b[i].col >> b[i].val;

    cout << "\n--- Transpose of A ---\n";
    Element t[50];
    transpose(a, t);
    print(t);

    cout << "\n--- A + B ---\n";
    add(a, b, c);
    print(c);

    cout << "\n--- A * B ---\n";
    multiply(a, b, c);
    print(c);

    return 0;
}
