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
    char peek() {
        if (isEmpty()) return '\0';
        return arr[top];
    }
};

bool isBalanced(const string& expr) {
    CharStack s;
    for (char ch : expr) {
        if (ch == '(' || ch == '[' || ch == '{') {
            s.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (s.isEmpty()) return false;
            char top = s.pop();
            if ((ch == ')' && top != '(') ||
                (ch == ']' && top != '[') ||
                (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    getline(cin, expr);
    if (isBalanced(expr))
        cout << "Balanced parentheses.\n";
    else
        cout << "Unbalanced parentheses.\n";
    return 0;
}
