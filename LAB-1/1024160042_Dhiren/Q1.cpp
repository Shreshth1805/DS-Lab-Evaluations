#include <iostream>
using namespace std;

#define MAX_SIZE 100

void create(int arr[], int &n) {
    cout << "Enter the elements of array\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void display(int arr[], int n) {
    cout << "The array you entered is\n";
    if (n == 0) {
        cout << "Sorry, no elements in the array\n";
        return;
    } else {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void insert(int arr[], int &n, int pos, int value) {
    if (pos < 0 || pos > n || n >= MAX_SIZE) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = value;
    n++;
    display(arr, n);
}

int linearsearch(int arr[], int n, int value) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == value) {
            cout << "Value is found at index: " << i << "\n";
            return i;
        }
    }
    cout << "Value not found\n";
    return -1;
}

void deleteArray(int arr[], int &n, int value) {
    int index = linearsearch(arr, n, value);
    if (index != -1) {
        for (int i = index; i < n - 1; i++) {
            arr[i] = arr[i + 1];
        }
        n--;
        display(arr, n);
    }
}

int main() {
    int arr[MAX_SIZE];
    int choice, n = 0; // initialize n to 0

    while (1) {
        cout << "1. Create\n";
        cout << "2. Display\n";
        cout << "3. Insert\n";
        cout << "4. Delete\n";
        cout << "5. Linear Search\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter the number of elements in the array: ";
            cin >> n;
            if (n > MAX_SIZE) {
                cout << "Size exceeds MAX_SIZE!\n";
                n = 0;
            } else {
                create(arr, n);
            }
        } else if (choice == 2) {
            display(arr, n);
        } else if (choice == 3) {
            int pos, value;
            cout << "Enter the index position (0-based): ";
            cin >> pos;
            cout << "Enter the value to insert: ";
            cin >> value;
            insert(arr, n, pos, value);
        } else if (choice == 4) {
            int value;
            cout << "Enter value to delete: ";
            cin >> value;
            deleteArray(arr, n, value);
        } else if (choice == 5) {
            int value;
            cout << "Enter the value you want to search: ";
            cin >> value;
            linearsearch(arr, n, value);
        } else if (choice == 6) {
            cout << "Exiting program...\n";
            break;
        } else {
            cout << "Wrong choice! Please enter a valid option.\n";
        }
    }
    return 0;
}
