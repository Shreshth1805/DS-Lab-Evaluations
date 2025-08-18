#include <iostream>
#include <string>
using namespace std;
bool isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int main() {
    string str = "Hello World";
    string result = "";
    for (char c : str) {
        if (!isVowel(c)) {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;
    return 0;
}