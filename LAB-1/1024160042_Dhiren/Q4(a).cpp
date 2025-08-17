#include <iostream>
using namespace std;

void reverseArray(int numbers[], int size) {
    int left = 0, right = size - 1;
    while (left < right) {
        swap(numbers[left], numbers[right]);
        left++;
        right--;
    }
}

int main() {
    int length;
    cout << "Enter number of elements: ";
    cin >> length;

    int elements[100];
    cout << "Enter elements: ";
    for (int i = 0; i < length; i++) 
        cin >> elements[i];

    reverseArray(elements, length);

    cout << "Reversed Array: ";
    for (int i = 0; i < length; i++) 
        cout << elements[i] << " ";
    cout << endl;

    return 0;
}
