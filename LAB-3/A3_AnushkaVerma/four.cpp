#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
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

int precedence(char op) {
    if (op == '^') return 3;
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

string infixToPostfix(const string& infix) {
    CharStack s;
    string postfix = "";
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            while (!s.isEmpty() && s.peek() != '(') {
                postfix += s.pop();
            }
            if (!s.isEmpty()) s.pop(); // Remove '('
        } else { // Operator
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch)) {
                postfix += s.pop();
            }
            s.push(ch);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}

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
    int peek() {
        if (isEmpty()) return 0;
        return arr[top];
    }
};

int evaluatePostfix(const string& expr) {
    IntStack s;
    for (size_t i = 0; i < expr.length(); ++i) {
        char ch = expr[i];
        if (isspace(ch)) continue;
        if (isdigit(ch)) {
            int num = 0;
            while (i < expr.length() && isdigit(expr[i])) {
                num = num * 10 + (expr[i] - '0');
                i++;
            }
            i--;
            s.push(num);
        } else {
            int val2 = s.pop();
            int val1 = s.pop();
            switch (ch) {
                case '+': s.push(val1 + val2); break;
                case '-': s.push(val1 - val2); break;
                case '*': s.push(val1 * val2); break;
                case '/': s.push(val1 / val2); break;
                case '^': s.push((int)pow(val1, val2)); break;
            }
        }
    }
    return s.pop();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    getline(cin, infix);
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Result: " << result << endl;

    return 0;
}
