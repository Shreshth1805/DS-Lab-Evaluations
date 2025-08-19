#include <iostream>
#include <string>
using namespace std;


void reverseString(string &str) {
    int n = str.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = str[i];
        str[i] = str[n - i - 1];
        str[n - i - 1] = temp;
    }
}

int main() {
    string str1, str2;

    cout << "CONCATENATING TWO STRINGS\n";
    cout << "Enter first string: ";
    getline(cin, str1);

    cout << "Enter second string: ";
    getline(cin, str2);

    string concatenated = str1 + str2;
    cout << "Concatenated string: " << concatenated << endl;

    cout << "REVERSING A STRING\n";
    cout << "Real string: " << str2 << "\n";

    reverseString(str2); 

    cout << "Reversed string: " << str2 << endl;

    return 0;
}