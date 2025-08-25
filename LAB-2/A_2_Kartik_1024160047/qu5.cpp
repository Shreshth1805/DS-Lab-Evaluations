#include <iostream>
using namespace std;


// a) Diagonal Matrix

class DiagonalMatrix {
    int *A;
    int n;
public:
    DiagonalMatrix(int n) {
        this->n = n;
        A = new int[n];
    }
    void set(int i, int j, int x) {
        if (i == j) A[i-1] = x;
    }
    int get(int i, int j) {
        if (i == j) return A[i-1];
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j) cout << A[i-1] << " ";
                else cout << "0 ";
            }
            cout << endl;
        }
    }
};


// b) Tri-diagonal Matrix

class TriDiagonalMatrix {
    int *A;
    int n;
public:
    TriDiagonalMatrix(int n) {
        this->n = n;
        A = new int[3*n - 2];
    }
    void set(int i, int j, int x) {
        if (i-j == 0) A[i-1] = x;                  
        else if (i-j == 1) A[n + (i-2)] = x;        
        else if (i-j == -1) A[2*n-1 + (i-1)] = x;      }
    int get(int i, int j) {
        if (i-j == 0) return A[i-1];
        else if (i-j == 1) return A[n + (i-2)];
        else if (i-j == -1) return A[2*n-1 + (i-1)];
        else return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};


// c) Lower Triangular Matrix

class LowerTriangularMatrix {
    int *A;
    int n;
public:
    LowerTriangularMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) {
            int index = i*(i-1)/2 + (j-1);
            A[index] = x;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int index = i*(i-1)/2 + (j-1);
            return A[index];
        }
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};


// d) Upper Triangular Matrix

class UpperTriangularMatrix {
    int *A;
    int n;
public:
    UpperTriangularMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i <= j) {
            int index = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
            A[index] = x;
        }
    }
    int get(int i, int j) {
        if (i <= j) {
            int index = (i-1)*n - (i-2)*(i-1)/2 + (j-i);
            return A[index];
        }
        return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};


// e) Symmetric Matrix

class SymmetricMatrix {
    int *A;
    int n;
public:
    SymmetricMatrix(int n) {
        this->n = n;
        A = new int[n*(n+1)/2];
    }
    void set(int i, int j, int x) {
        if (i >= j) {
            int index = i*(i-1)/2 + (j-1);
            A[index] = x;
        } else {
            int index = j*(j-1)/2 + (i-1);
            A[index] = x;
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            int index = i*(i-1)/2 + (j-1);
            return A[index];
        } else {
            int index = j*(j-1)/2 + (i-1);
            return A[index];
        }
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter size of square matrix: ";
    cin >> n;

    cout << "\n--- Diagonal Matrix ---\n";
    DiagonalMatrix dm(n);
    for (int i = 1; i <= n; i++) dm.set(i,i,i*10);
    dm.display();

    cout << "\n--- Tri-diagonal Matrix ---\n";
    TriDiagonalMatrix tdm(n);
    for (int i = 1; i <= n; i++) {
        tdm.set(i,i,10*i);
        if (i>1) tdm.set(i,i-1,1);
        if (i<n) tdm.set(i,i+1,2);
    }
    tdm.display();

    cout << "\n--- Lower Triangular Matrix ---\n";
    LowerTriangularMatrix ltm(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            ltm.set(i,j, i+j);
    ltm.display();

    cout << "\n--- Upper Triangular Matrix ---\n";
    UpperTriangularMatrix utm(n);
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            utm.set(i,j, i+j);
    utm.display();

    cout << "\n--- Symmetric Matrix ---\n";
    SymmetricMatrix sm(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            sm.set(i,j, i+j);
    sm.display();

    return 0;
}
