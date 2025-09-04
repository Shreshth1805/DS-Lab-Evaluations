#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#define MAX 1000

class IntStack {
    int arr[MAX];
    int top;
public:
    IntStack() { top = -1; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == MAX - 1; }
    void push(int x) {
        if (isFull()) return;
        arr[++top] = x;
    }
    int pop() {
        if (isEmpty()) return 0;
        return arr[top--];
    }
};

int evaluatePostfix(const string& expr) {
    IntStack s;
    for (char ch : expr) {
        if (isdigit(ch)) {
            s.push(ch - '0');
        } else if (ch == ' ') {
            continue;
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string postfix;
    cout << "Enter postfix expression (single-digit operands, no spaces needed): ";
    getline(cin, postfix);
    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;
    return 0;
}
