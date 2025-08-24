#include <iostream>
using namespace std;

// (a) Diagonal Matrix
class DiagonalMatrix {
    int *arr;
    int n;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        arr = new int[n];
    }
    void set(int i, int j, int val) {
        if (i == j) arr[i-1] = val;
    }
    int get(int i, int j) {
        if (i == j) return arr[i-1];
        else return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

// (b) Tri-Diagonal Matrix
class TriDiagonalMatrix {
    int *arr;
    int n;
public:
    TriDiagonalMatrix(int n) {
        this->n = n;
        arr = new int[3*n - 2];  // store 3n-2 elements
    }
    void set(int i, int j, int val) {
        if (i-j == 1) arr[i-2] = val;            // lower diagonal
        else if (i-j == 0) arr[n-1 + i-1] = val; // main diagonal
        else if (i-j == -1) arr[2*n-1 + i-1] = val; // upper diagonal
    }
    int get(int i, int j) {
        if (i-j == 1) return arr[i-2];
        else if (i-j == 0) return arr[n-1 + i-1];
        else if (i-j == -1) return arr[2*n-1 + i-1];
        else return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// (c) Lower Triangular Matrix
class LowerTriangularMatrix {
    int *arr;
    int n;
public:
    LowerTriangularMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int val) {
        if (i >= j) arr[(i*(i-1))/2 + (j-1)] = val;
    }
    int get(int i, int j) {
        if (i >= j) return arr[(i*(i-1))/2 + (j-1)];
        else return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// (d) Upper Triangular Matrix
class UpperTriangularMatrix {
    int *arr;
    int n;
public:
    UpperTriangularMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int val) {
        if (i <= j) arr[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = val;
    }
    int get(int i, int j) {
        if (i <= j) return arr[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
        else return 0;
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

// (e) Symmetric Matrix
class SymmetricMatrix {
    int *arr;
    int n;
public:
    SymmetricMatrix(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
    }
    void set(int i, int j, int val) {
        if (i >= j) arr[(i*(i-1))/2 + (j-1)] = val;
        else arr[(j*(j-1))/2 + (i-1)] = val;  // symmetry
    }
    int get(int i, int j) {
        if (i >= j) return arr[(i*(i-1))/2 + (j-1)];
        else return arr[(j*(j-1))/2 + (i-1)];
    }
    void display() {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4;

    cout << "\nDiagonal Matrix:\n";
    DiagonalMatrix d(n);
    d.set(1,1,5); d.set(2,2,8); d.set(3,3,9); d.set(4,4,12);
    d.display();

    cout << "\nTri-Diagonal Matrix:\n";
    TriDiagonalMatrix t(n);
    t.set(1,1,1); t.set(2,2,2); t.set(3,3,3); t.set(4,4,4);
    t.set(2,1,5); t.set(3,2,6); t.set(4,3,7); // lower
    t.set(1,2,9); t.set(2,3,10); t.set(3,4,11); // upper
    t.display();

    cout << "\nLower Triangular Matrix:\n";
    LowerTriangularMatrix l(n);
    l.set(1,1,1);
    l.set(2,1,2); l.set(2,2,3);
    l.set(3,1,4); l.set(3,2,5); l.set(3,3,6);
    l.set(4,1,7); l.set(4,2,8); l.set(4,3,9); l.set(4,4,10);
    l.display();

    cout << "\nUpper Triangular Matrix:\n";
    UpperTriangularMatrix u(n);
    u.set(1,1,1); u.set(1,2,2); u.set(1,3,3); u.set(1,4,4);
    u.set(2,2,5); u.set(2,3,6); u.set(2,4,7);
    u.set(3,3,8); u.set(3,4,9);
    u.set(4,4,10);
    u.display();

    cout << "\nSymmetric Matrix:\n";
    SymmetricMatrix s(n);
    s.set(1,1,1); s.set(2,1,2); s.set(3,1,3); s.set(4,1,4);
    s.set(2,2,5); s.set(3,2,6); s.set(4,2,7);
    s.set(3,3,8); s.set(4,3,9);
    s.set(4,4,10);
    s.display();

    return 0;
}
