#include<iostream>
using namespace std;

#define MAX 100

struct Term {
    int row, col, val;
};


void printSparse(Term a[]) {
    cout << "\nRow Col Value\n";
    for (int i = 0; i <= a[0].val; i++) {
        cout << a[i].row << " " << a[i].col << " " << a[i].val << endl;
    }
}


void transpose(Term a[], Term b[]) {
    int n = a[0].val;
    b[0].row = a[0].col;
    b[0].col = a[0].row;
    b[0].val = n;

    if (n > 0) {
        int pos = 1;
        for (int col = 0; col < a[0].col; col++) {
            for (int i = 1; i <= n; i++) {
                if (a[i].col == col) {
                    b[pos].row = a[i].col;
                    b[pos].col = a[i].row;
                    b[pos].val = a[i].val;
                    pos++;
                }
            }
        }
    }
}

void add(Term a[], Term b[], Term c[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "Addition not possible!" << endl;
        return;
    }

    c[0].row = a[0].row;
    c[0].col = a[0].col;

    int i=1, j=1, k=1;
    while (i <= a[0].val && j <= b[0].val) {
        if (a[i].row < b[j].row || 
           (a[i].row == b[j].row && a[i].col < b[j].col)) {
            c[k++] = a[i++];
        }
        else if (b[j].row < a[i].row || 
                (b[j].row == a[i].row && b[j].col < a[i].col)) {
            c[k++] = b[j++];
        }
        else {
            c[k].row = a[i].row;
            c[k].col = a[i].col;
            c[k].val = a[i].val + b[j].val;
            i++; j++; k++;
        }
    }
    while (i <= a[0].val) c[k++] = a[i++];
    while (j <= b[0].val) c[k++] = b[j++];

    c[0].val = k-1;
}

void multiply(Term a[], Term b[], Term c[]) {
    if (a[0].col != b[0].row) {
        cout << "Multiplication not possible!" << endl;
        return;
    }

    Term bt[MAX];
    transpose(b, bt);

    c[0].row = a[0].row;
    c[0].col = b[0].col;
    c[0].val = 0;

    int k = 1;
    for (int i = 1; i <= a[0].val;) {
        int r = a[i].row;
        for (int j = 1; j <= bt[0].val;) {
            int ccol = bt[j].row;
            int x = i, y = j;
            int sum = 0;

            while (x <= a[0].val && a[x].row == r && 
                   y <= bt[0].val && bt[y].row == ccol) {
                if (a[x].col < bt[y].col) x++;
                else if (a[x].col > bt[y].col) y++;
                else {
                    sum += a[x].val * bt[y].val;
                    x++; y++;
                }
            }

            if (sum != 0) {
                c[k].row = r;
                c[k].col = ccol;
                c[k].val = sum;
                k++;
            }

            while (y <= bt[0].val && bt[y].row == ccol) y++;
        }

        while (i <= a[0].val && a[i].row == r) i++;
    }
    c[0].val = k-1;
}
