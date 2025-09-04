#include <iostream>
using namespace std;

class SymmetricMatrix {
    int *arr;   
    int n;      

public:
    
    SymmetricMatrix(int size) {
        n = size;
        arr = new int[n * (n + 1) / 2]; 
    }

    ~SymmetricMatrix() {
        delete[] arr;
    }
    int index(int i, int j) {
        return (i * (i + 1)) / 2 + j;   
    }
    void set(int i, int j, int val) {
        if (i >= j) {
            arr[index(i, j)] = val;  
        } else {
            arr[index(j, i)] = val;   
        }
    }
    int get(int i, int j) {
        if (i >= j) {
            return arr[index(i, j)];
        } else {
            return arr[index(j, i)];
        }
    }

  
    void display() {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int n;
    cout << "Enter size of symmetric matrix (n): ";
    cin >> n;

    SymmetricMatrix sm(n);

    cout << "Enter elements of the matrix (" << n << "x" << n << "):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            sm.set(i, j, val);
        }
    }

    cout << "\nThe Symmetric Matrix is:" << endl;
    sm.display();

    return 0;
}
