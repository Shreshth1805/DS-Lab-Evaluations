#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    char ch;
    cout << "Enter an uppercase character: ";
    cin >> ch;

    if (isupper(ch)) {
        cout << "Lowercase: " << char(tolower(ch)) << endl;
    } else {
        cout << "Character is not uppercase!" << endl;
    }

    return 0;
}
