#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, num;
    Element data[100];
};

void display(SparseMatrix s) {
    cout << "Row Col Val\n";
    for (int i = 0; i < s.num; i++)
        cout << s.data[i].row << "   " << s.data[i].col << "   " << s.data[i].val << endl;
}

SparseMatrix transpose(SparseMatrix s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.num = s.num;
    int k = 0;
    for (int i = 0; i < s.cols; i++) {
        for (int j = 0; j < s.num; j++) {
            if (s.data[j].col == i) {
                t.data[k].row = s.data[j].col;
                t.data[k].col = s.data[j].row;
                t.data[k].val = s.data[j].val;
                k++;
            }
        }
    }
    return t;
}

SparseMatrix multiply(SparseMatrix s1, SparseMatrix s2) {
    SparseMatrix product;
    product.rows = s1.rows;
    product.cols = s2.cols;
    product.num = 0;
    SparseMatrix s2T = transpose(s2);
    for (int i = 0; i < s1.rows; i++) {
        for (int j = 0; j < s2T.rows; j++) {
            int sum = 0;
            for (int x = 0; x < s1.num; x++) {
                if (s1.data[x].row != i) continue;
                for (int y = 0; y < s2T.num; y++) {
                    if (s2T.data[y].row != j) continue;
                    if (s1.data[x].col == s2T.data[y].col) {
                        sum += s1.data[x].val * s2T.data[y].val;
                    }
                }
            }
            if (sum != 0) {
                product.data[product.num].row = i;
                product.data[product.num].col = j;
                product.data[product.num].val = sum;
                product.num++;
            }
        }
    }
    return product;
}

int main() {
    SparseMatrix s1, s2;
    cin >> s1.rows >> s1.cols >> s1.num;
    for (int i = 0; i < s1.num; i++)
        cin >> s1.data[i].row >> s1.data[i].col >> s1.data[i].val;
    cin >> s2.rows >> s2.cols >> s2.num;
    for (int i = 0; i < s2.num; i++)
        cin >> s2.data[i].row >> s2.data[i].col >> s2.data[i].val;
    if (s1.cols != s2.rows) return 0;
    SparseMatrix prod = multiply(s1, s2);
    display(prod);
    return 0;
}
