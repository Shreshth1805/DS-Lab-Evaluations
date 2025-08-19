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
    void set(int i, int j, int value) {
        if (i >= j)
            arr[i * (i - 1) / 2 + (j - 1)] = value;
        else
            arr[j * (j - 1) / 2 + (i - 1)] = value; // Use symmetry
    }
    int get(int i, int j) {
        if (i >= j)
            return arr[i * (i - 1) / 2 + (j - 1)];
        else
            return arr[j * (j - 1) / 2 + (i - 1)];
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~SymmetricMatrix() {
        delete[] arr;
    }
};
int main() {
    SymmetricMatrix sm(4);
    sm.set(1, 1, 1);
    sm.set(2, 1, 2);
    sm.set(2, 2, 3);
    sm.set(3, 1, 4);
    sm.set(3, 2, 5);
    sm.set(3, 3, 6);
    sm.set(4, 1, 7);
    sm.set(4, 2, 8);
    sm.set(4, 3, 9);
    sm.set(4, 4, 10);
    cout << "Symmetric Matrix:\n";
    sm.display();
    return 0;
}
