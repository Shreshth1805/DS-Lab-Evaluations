#include <iostream>
#include <string>
using namespace std;

#define MAX 1000

class CharStack {
    char arr[MAX];
    int top;
public:
    CharStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(char x) {
        if (isFull()) return;
        arr[++top] = x;
    }
    char pop() {
        if (isEmpty()) return '\0';
        return arr[top--];
    }
};

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    CharStack s;
    for (char ch : input) {
        s.push(ch);
    }
    cout << "Reversed string: ";
    while (!s.isEmpty()) {
        cout << s.pop();
    }
    cout << endl;
    return 0;
}
