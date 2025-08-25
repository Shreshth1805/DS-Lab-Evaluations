#include <iostream>
using namespace std;

struct Element {
    int row, col, val;
};

void display(Element s[]) {
    cout << "\nRow\tCol\tValue\n";
    for (int i = 0; i <= s[0].val; i++) {
        cout << s[i].row << "\t" << s[i].col << "\t" << s[i].val << endl;
    }
}


// a) Transpose of Sparse Matrix

void transpose(Element s[], Element t[]) {
    int m = s[0].row, n = s[0].col, num = s[0].val;
    t[0].row = n; t[0].col = m; t[0].val = num;

    int k = 1;
    for (int i = 0; i < n; i++) {   
        for (int j = 1; j <= num; j++) {
            if (s[j].col == i) {
                t[k].row = s[j].col;
                t[k].col = s[j].row;
                t[k].val = s[j].val;
                k++;
            }
        }
    }
}


// b) Addition of two sparse matrices

void add(Element s1[], Element s2[], Element sum[]) {
    if (s1[0].row != s2[0].row || s1[0].col != s2[0].col) {
        cout << "Addition not possible (dimension mismatch)\n";
        return;
    }

    sum[0].row = s1[0].row;
    sum[0].col = s1[0].col;

    int i=1, j=1, k=1;
    while (i <= s1[0].val && j <= s2[0].val) {
        if (s1[i].row < s2[j].row || 
           (s1[i].row == s2[j].row && s1[i].col < s2[j].col)) {
            sum[k++] = s1[i++];
        }
        else if (s2[j].row < s1[i].row || 
                (s1[i].row == s2[j].row && s2[j].col < s1[i].col)) {
            sum[k++] = s2[j++];
        }
        else { 
            sum[k] = s1[i];
            sum[k].val = s1[i].val + s2[j].val;
            i++; j++; k++;
        }
    }
    while (i <= s1[0].val) sum[k++] = s1[i++];
    while (j <= s2[0].val) sum[k++] = s2[j++];

    sum[0].val = k-1;
}


// c) Multiplication of two sparse matrices

void multiply(Element s1[], Element s2[], Element prod[]) {
    if (s1[0].col != s2[0].row) {
        cout << "Multiplication not possible (dimension mismatch)\n";
        return;
    }

    prod[0].row = s1[0].row;
    prod[0].col = s2[0].col;
    prod[0].val = 0;

    int k = 1;

    for (int i = 1; i <= s1[0].val; i++) {
        for (int j = 1; j <= s2[0].val; j++) {
            if (s1[i].col == s2[j].row) {
                int r = s1[i].row;
                int c = s2[j].col;
                int pos = -1;
                for (int x = 1; x < k; x++) {
                    if (prod[x].row == r && prod[x].col == c) {
                        pos = x;
                        break;
                    }
                }
                if (pos == -1) { 
                    prod[k].row = r;
                    prod[k].col = c;
                    prod[k].val = s1[i].val * s2[j].val;
                    k++;
                } else {
                    prod[pos].val += s1[i].val * s2[j].val;
                }
            }
        }
    }

    prod[0].val = k-1;
}

int main() {
   
    Element s1[10] = { {3,3,3}, {0,0,5}, {1,1,8}, {2,2,10} };

   
    Element s2[10] = { {3,3,3}, {0,1,7}, {1,2,9}, {2,0,6} };

    cout << "\nMatrix 1:";
    display(s1);

    cout << "\nMatrix 2:";
    display(s2);

   
    Element t[10];
    transpose(s1, t);
    cout << "\nTranspose of Matrix 1:";
    display(t);

    
    Element sum[20];
    add(s1, s2, sum);
    cout << "\nAddition (Matrix1 + Matrix2):";
    display(sum);

    
    Element prod[30];
    multiply(s1, s2, prod);
    cout << "\nMultiplication (Matrix1 * Matrix2):";
    display(prod);

    return 0;
}
