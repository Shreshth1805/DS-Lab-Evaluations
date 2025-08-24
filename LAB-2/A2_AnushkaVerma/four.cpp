#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

// (a) Concatenate
void concatenateStrings(char str1[], char str2[]) {
    strcat(str1, str2);
    cout << "Concatenated String: " << str1 << endl;
}

// (b) Reverse
void reverseString(char str[]) {
    int n = strlen(str);
    cout << "Reversed String: ";
    for (int i = n - 1; i >= 0; i--)
        cout << str[i];
    cout << endl;
}

// (c) Delete vowels
void deleteVowels(char str[]) {
    char result[100];
    int j = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char ch = tolower(str[i]);
        if (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u') {
            result[j++] = str[i];
        }
    }
    result[j] = '\0';
    cout << "String without vowels: " << result << endl;
}

// (d) Sort strings alphabetically
void sortStrings(char arr[][100], int n) {
    char temp[100];
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i], arr[j]) > 0) {
                strcpy(temp, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], temp);
            }
        }
    }
    cout << "Sorted Strings: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// (e) Uppercase to lowercase
void toLowercase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);
    }
    cout << "Lowercase String: " << str << endl;
}

int main() {
    char str1[100], str2[100];

    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;

    // (a) Concatenate
    concatenateStrings(str1, str2);

    // (b) Reverse
    cout << "Enter a string to reverse: ";
    char str3[100];
    cin >> str3;
    reverseString(str3);

    // (c) Delete vowels
    cout << "Enter a string to remove vowels: ";
    char str4[100];
    cin >> str4;
    deleteVowels(str4);

    // (d) Sort strings
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    char arr[10][100];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sortStrings(arr, n);

    // (e) Uppercase to lowercase
    cout << "Enter a string in uppercase: ";
    char str5[100];
    cin >> str5;
    toLowercase(str5);

    return 0;
}
