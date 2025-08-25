#include<iostream>
using namespace std;

const int MAX_SIZE = 100;

void rowColumnSum() {
    int r, c;
    cout << "Enter number of rows: ";
    cin >> r;
    cout << "Enter number of columns: ";
    cin >> c;
    
    int A[MAX_SIZE][MAX_SIZE];
    cout << "Enter the elements of the matrix:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << "A[" << i << "][" << j << "]: ";
            cin >> A[i][j];
        }
    }
    cout << "\nThe Matrix:\n";
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << A[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "\nSum of each row:\n";
    for(int i = 0; i < r; i++) {
        int rowSum = 0;
        for(int j = 0; j < c; j++) {
            rowSum += A[i][j];
        }
        cout << "Row " << i << " sum = " << rowSum << endl;
    }
    cout << "\nSum of each column:\n";
    for(int j = 0; j < c; j++) {
        int colSum = 0;
        for(int i = 0; i < r; i++) {
            colSum += A[i][j];
        }
        cout << "Column " << j << " sum = " << colSum << endl;
    }
    int totalSum = 0;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
      totalSum += A[i][j];
        }
    }
    cout << "\nTotal sum of all elements = " << totalSum << endl;
}
int main() {
    rowColumnSum();
    return 0;
}