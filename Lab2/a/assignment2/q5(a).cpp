#include <iostream>
using namespace std;
class DiagonalMatrix {
    int *arr;
    int n;
public:
    DiagonalMatrix(int size) {
        n = size;
        arr = new int[n];
    }
    void set(int i, int j, int value) {
        if (i == j)
            arr[i - 1] = value;
    }
    int get(int i, int j) {
        if (i == j)
            return arr[i - 1];
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
};
int main() {
    DiagonalMatrix d(3);
    d.set(1, 1, 5);
    d.set(2, 2, 8);
    d.set(3, 3, 3);
    d.display();
    return 0;
}
