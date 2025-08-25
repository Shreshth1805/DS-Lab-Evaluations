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

SparseMatrix add(SparseMatrix s1, SparseMatrix s2) {
    SparseMatrix sum;
    sum.rows = s1.rows;
    sum.cols = s1.cols;
    sum.num = 0;

    int i = 0, j = 0, k = 0;
    while (i < s1.num && j < s2.num) {
        if (s1.data[i].row < s2.data[j].row ||
           (s1.data[i].row == s2.data[j].row && s1.data[i].col < s2.data[j].col)) {
            sum.data[k++] = s1.data[i++];
        }
        else if (s2.data[j].row < s1.data[i].row ||
                (s2.data[j].row == s1.data[i].row && s2.data[j].col < s1.data[i].col)) {
            sum.data[k++] = s2.data[j++];
        }
        else {
            sum.data[k] = s1.data[i];
            sum.data[k].val = s1.data[i].val + s2.data[j].val;
            i++; j++; k++;
        }
    }
    while (i < s1.num) sum.data[k++] = s1.data[i++];
    while (j < s2.num) sum.data[k++] = s2.data[j++];

    sum.num = k;
    return sum;
}

int main() {
    SparseMatrix s1, s2;
    cin >> s1.rows >> s1.cols >> s1.num;
    for (int i = 0; i < s1.num; i++)
        cin >> s1.data[i].row >> s1.data[i].col >> s1.data[i].val;
    cin >> s2.rows >> s2.cols >> s2.num;
    for (int i = 0; i < s2.num; i++)
        cin >> s2.data[i].row >> s2.data[i].col >> s2.data[i].val;
    SparseMatrix sum = add(s1, s2);
    display(sum);
    return 0;
}
