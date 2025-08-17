#include <iostream>
using namespace std;

// Q1
void createArray(int arr[], int &n) {
    cout << "Enter size: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

void insertElement(int arr[], int &n) {
    int pos, val;
    cout << "Enter position and value: ";
    cin >> pos >> val;
    for (int i = n; i > pos; i--) arr[i] = arr[i - 1];
    arr[pos] = val;
    n++;
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position: ";
    cin >> pos;
    for (int i = pos; i < n - 1; i++) arr[i] = arr[i + 1];
    n--;
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter key: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Found at index " << i << endl;
            return;
        }
    }
    cout << "Not found" << endl;
}

int main() {
    int arr[100], n = 0, choice;
    do {
        cout << "1.CREATE 2.DISPLAY 3.INSERT 4.DELETE 5.SEARCH 6.EXIT\n";
        cin >> choice;
        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
        }
    } while (choice != 6);
    return 0;
}

// Q2
void removeDuplicates(int arr[], int &n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n;) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < n - 1; k++) arr[k] = arr[k + 1];
                n--;
            } else {
                j++;
            }
        }
    }
}

// Q3

void q3_output() {
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++) cout << arr[i];
}

// Output for Q3 will be 10000

// Q4a
void reverseArray(int arr[], int n) {
    for (int i = 0; i < n / 2; i++) {
        int temp = arr[i];
        arr[i] = arr[n - i - 1];
        arr[n - i - 1] = temp;
    }
}

// Q4b
void matrixMultiplication() {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    if (c1 != r2) {
        cout << "Not possible" << endl;
        return;
    }
    int A[10][10], B[10][10], C[10][10] = {0};
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++) cin >> A[i][j];
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++) cin >> B[i][j];
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c2; j++)
            for (int k = 0; k < c1; k++)
                C[i][j] += A[i][k] * B[k][j];
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) cout << C[i][j] << " ";
        cout << endl;
    }
}

// Q4c
void transposeMatrix() {
    int r, c;
    cin >> r >> c;
    int A[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> A[i][j];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) cout << A[j][i] << " ";
        cout << endl;
    }
}

// Q5
void sumRowsCols() {
    int r, c;
    cin >> r >> c;
    int A[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> A[i][j];
    for (int i = 0; i < r; i++) {
        int sum = 0;
        for (int j = 0; j < c; j++) sum += A[i][j];
        cout << "Row " << i << " sum = " << sum << endl;
    }
    for (int j = 0; j < c; j++) {
        int sum = 0;
        for (int i = 0; i < r; i++) sum += A[i][j];
        cout << "Col " << j << " sum = " << sum << endl;
    }
}


