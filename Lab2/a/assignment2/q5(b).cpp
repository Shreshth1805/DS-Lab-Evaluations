#include <iostream>
using namespace std;
class TriDiagonal {
    int *arr;
    int n;
public:
    TriDiagonal(int size) {
        n = size;
        arr = new int[3 * n - 2]; // Space optimized
    }
    void set(int i, int j, int value) {
        if (i - j == 1)
            arr[i - 2] = value;           // Lower diagonal
        else if (i == j)
            arr[n - 1 + i - 1] = value;   // Main diagonal
        else if (i - j == -1)
            arr[2 * n - 1 + i - 1] = value; // Upper diagonal
    }
    int get(int i, int j) {
        if (i - j == 1)
            return arr[i - 2];
        else if (i == j)
            return arr[n - 1 + i - 1];
        else if (i - j == -1)
            return arr[2 * n - 1 + i - 1];
        else
            return 0;
    }
    void display() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << get(i, j) << " ";
            }
            cout << endl;
        }
    }
    ~TriDiagonal() {
        delete[] arr;
    }
};
int main() {
    TriDiagonal td(4);
    td.set(1, 1, 4);
    td.set(1, 2, 5);
    td.set(2, 1, 6);
    td.set(2, 2, 7);
    td.set(2, 3, 8);
    td.set(3, 2, 9);
    td.set(3, 3, 1);
    td.set(3, 4, 2);
    td.set(4, 3, 3);
    td.set(4, 4, 10);
    cout << "Tri-diagonal Matrix:\n";
    td.display();
    return 0;
}
