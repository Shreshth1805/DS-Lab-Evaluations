#include <iostream>
using namespace std;

int main() {
    int rows = 3, cols = 3;
    int arr[3][3] = {
        {10, 22, 32},
        {41, 51, 61},
        {72, 90, 100}
    };

    
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Sum of row " << i + 1 << " = " << rowSum << endl;
    }

   
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << "Sum of column " << j + 1 << " = " << colSum << endl;
    }

    return 0;
}