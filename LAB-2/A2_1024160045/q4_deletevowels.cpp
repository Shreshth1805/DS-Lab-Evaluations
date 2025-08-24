#include <iostream>
#include <string>
using namespace std;

int main() {
    string str, result="";
    cout << "Enter a string: ";
    getline(cin, str);
    for(char c : str) {
        if(!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
             c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result += c;
        }
    }
    cout << "String without vowels: " << result << endl;
    return 0;
}
