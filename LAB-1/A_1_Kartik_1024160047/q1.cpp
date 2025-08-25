#include <iostream>
using namespace std;
const int size=100;
int arr[size];
int length;

void createarr(){
    cout << "Enter Size of Array";
    cin >> length;
    cout << "enter" <<length << "Numbers";
    for (int i=0;i<length;i++){
        cin >> arr[i];
    }

}

void showarr (){
    cout << "Array is : ";
    for (int i=0;i<length;i++){
        cout << arr[i];
    }
}

void insert(){
    int pos,value;
    cout << "Position and value to insert: ";
    cin >> pos >> value;
    for(int i=length;i>pos;i--){
        arr[i]=arr[i-1];
    }
    arr[pos]=value;
    length++;
}

void deleteelement(){
    int position;
    cout << "Enter position to remove : ";
    cin >> position;
    for (int i = position; i < length - 1; i++) {
        arr[i] = arr[i + 1];
    }
    length--;
}

void linearSearch(){
    int target;
    cout << "Enter value to search: ";
    cin >> target;

    for (int i = 0; i < length; i++) {
        if (arr[i] == target) {
            cout << "Found at index " << i << "\n";
            return;
        }
    }
    cout << "Not found.\n";
}



int main() {
    int option;
    do {
        cout << "\n==== ARRAY MENU ====\n"
             << "1. Create\n"
             << "2. Display\n"
             << "3. Insert\n"
             << "4. Delete\n"
             << "5. Search\n"
             << "6. Exit\n"
             << "option: ";
        cin >> option;

        switch (option) {
            case 1: createarr(); break;
            case 2: showarr(); break;
            case 3: insert(); break;
            case 4: deleteelement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "Goodbye!\n"; break;
            default: cout << "Invalid option, try again.\n";
        }
    } while (option != 6);

    return 0;
}