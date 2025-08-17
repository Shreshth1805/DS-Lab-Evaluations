#include <iostream>
using namespace std;
#define MAX 100
int arr[MAX];
int n = 0;
void createArray() {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}
void displayArray() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
void insertElement() {
    int pos, val;
    cout << "Enter position (1 to " << n + 1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> val;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];
    arr[pos - 1] = val;
    n++;
}
void deleteElement() {
    int pos;
    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];
    n--;
}
void linearSearch() {
    int val, found = 0;
    cout << "Enter value to search: ";
    cin >> val;
    for (int i = 0; i < n; i++) {
        if (arr[i] == val) {
            cout << "Element found at position " << i + 1 << "\n";
            found = 1;
            break;
        }
    }
    if (!found)
        cout << "Element not found.\n";
}
void removeDuplicates() {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++)
                    arr[k] = arr[k + 1];
                n--;
            } else {
                j++;
            }
        }
    }
    cout << "Array after removing duplicates: ";
    displayArray();
}
void predictOutput() {
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++)
        cout << arr[i];
    cout << "\nExpected Output: 10000\n";
}
void reverseArray() {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
    cout << "Reversed array: ";
    displayArray();
}
void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10] = {0};
    int r1, c1, r2, c2;
    cout << "Enter rows and cols of first matrix: ";
    cin >> r1 >> c1;
    cout << "Enter rows and cols of second matrix: ";
    cin >> r2 >> c2;
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!\n";
        return;
    }
    cout << "Enter first matrix:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> a[i][j];
    cout << "Enter second matrix:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> b[i][j];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                c[i][j] += a[i][k] * b[k][j];
    cout << "Resultant Matrix:\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++)
            cout << c[i][j] << " ";
        cout << "\n";
    }
}
void transposeMatrix() {
    int a[10][10], t[10][10];
    int r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            t[j][i] = a[i][j];
    cout << "Transpose:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++)
            cout << t[i][j] << " ";
        cout << "\n";
    }
}
void sumRowsCols() {
    int a[10][10], r, c;
    cout << "Enter rows and cols: ";
    cin >> r >> c;
    cout << "Enter matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> a[i][j];
    for (int i = 0; i < r; i++) {
        int sumRow = 0;
        for (int j = 0; j < c; j++)
            sumRow += a[i][j];
        cout << "Sum of row " << i + 1 << " = " << sumRow << "\n";
    }
    for (int j = 0; j < c; j++) {
        int sumCol = 0;
        for (int i = 0; i < r; i++)
            sumCol += a[i][j];
        cout << "Sum of column " << j + 1 << " = " << sumCol << "\n";
    }
}
int main() {
    int choice;
    while (true) {
        cout << "\n==== LAB ASSIGNMENT MENU ====\n";
        cout << "1. Array Operations (Create, Display, Insert, Delete, Search)\n";
        cout << "2. Remove Duplicates from Array\n";
        cout << "3. Predict Output Program\n";
        cout << "4. Reverse Array\n";
        cout << "5. Matrix Multiplication\n";
        cout << "6. Transpose of Matrix\n";
        cout << "7. Sum of Rows and Columns of Matrix\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int subChoice;
                while (true) {
                    cout << "\n--- Array Menu ---\n";
                    cout << "1. Create\n2. Display\n3. Insert\n4. Delete\n5. Search\n6. Back to Main Menu\n";
                    cin >> subChoice;
                    if (subChoice == 1) createArray();
                    else if (subChoice == 2) displayArray();
                    else if (subChoice == 3) insertElement();
                    else if (subChoice == 4) deleteElement();
                    else if (subChoice == 5) linearSearch();
                    else if (subChoice == 6) break;
                    else cout << "Invalid choice!\n";
                }
                break;
            }
            case 2: removeDuplicates(); break;
            case 3: predictOutput(); break;
            case 4: reverseArray(); break;
            case 5: matrixMultiplication(); break;
            case 6: transposeMatrix(); break;
            case 7: sumRowsCols(); break;
            case 8: return 0;
            default: cout << "Invalid choice!\n";
        }
    }
}