#include <iostream>
using namespace std;

#define MAX_SIZE 100   // maximum capacity of array

// Create Array
void createArray(float arr[], int &n) {
    cout << "Start entering elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

// Display Array
void displayArray(float arr[], int n) {
    if (n == 0) {
        cout << "Oops! NO ELEMENTS HAVE BEEN ADDED\n";
        return;
    }
    cout << "ALL ELEMENTS ARE AS FOLLOWS:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\n";
    }
}

// Insert into Array
void insertArray(float arr[], int &n, float value, int pos) {
    if (pos < 0 || pos > n || n >= MAX_SIZE) {
        cout << "Invalid position or array full!\n";
        return;
    }
    // Shift elements to the right
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    displayArray(arr, n);
}

// Linear Search
int linearSearch(float arr[], int n, float value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Value is found at index: " << i << "\n";
            return i;
        }
    }
    cout << "Value not found\n";
    return -1;
}

// Delete from Array
void deleteArray(float arr[], int &n, float value) {
    int index = linearSearch(arr, n, value);
    if (index != -1) {
        // Shift elements to the left
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        displayArray(arr, n);
    }
}

int main() {
    cout << "---------------MENU-----------------\n";
    float arr[MAX_SIZE];
    int n = 0;
    int choice;

    while (true) {
        cout << "1. CREATE\n2. DISPLAY\n3. INSERT\n4. DELETE\n5. LINEAR SEARCH\n6. EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter number of elements: ";
            cin >> n;
            if (n > MAX_SIZE) {
                cout << "Too many elements! Max allowed: " << MAX_SIZE << "\n";
                n = 0;
            } else {
                createArray(arr, n);
            }
        } 
        else if (choice == 2) {
            displayArray(arr, n);
        } 
        else if (choice == 3) {
            float value;
            int pos;
            cout << "Enter value to insert: ";
            cin >> value;
            cout << "Enter position (index): ";
            cin >> pos;
            insertArray(arr, n, value, pos);
        } 
        else if (choice == 4) {
            float value;
            cout << "Enter value to delete: ";
            cin >> value;
            deleteArray(arr, n, value);
        } 
        else if (choice == 5) {
            float value;
            cout << "Enter value to search: ";
            cin >> value;
            linearSearch(arr, n, value);
        } 
        else if (choice == 6) {
            break;
        } 
        else {
            cout << "WRONG CHOICE. TRY AGAIN!\n";
        }
    }
    return 0;
}