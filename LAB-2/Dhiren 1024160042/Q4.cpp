#include <iostream>
#include <string>
using namespace std;
void concatenateStrings()
{
    string str1, str2;
    cout << "\nEnter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);
    string result = str1 + str2;
    cout << "Concatenated string: " << result << endl;
}
void reverseString()
{
    string str;
    cout << "\nEnter a string to reverse: ";
    getline(cin, str);
    int len = str.length();
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
    cout << "Reversed string: " << str << endl;
}
bool isVowel(char ch)
{
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
}
void deleteVowels()
{
    string str, result = "";
    cout << "\nEnter a string: ";
    getline(cin, str);
    for (char ch : str)
    {
        if (!isVowel(ch))
        {
            result += ch;
        }
    }
    cout << "String after removing vowels: " << result << endl;
}
void sortStrings()
{
    int n;
    cout << "\nEnter number of strings: ";
    cin >> n;
    cin.ignore();
    string arr[100];
    cout << "Enter " << n << " strings:\n";
    for (int i = 0; i < n; i++)
    {
        getline(cin, arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    cout << "Sorted strings:\n";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << endl;
    }
}
void convertToLowercase()
{
    char ch;
    cout << "\nEnter an uppercase character: ";
    cin >> ch;
    if (ch >= 'A' && ch <= 'Z')
    {
        ch = ch + (int)32;
        cout << "Lowercase character: " << ch << endl;
    }
    else
    {
        cout << "Character is not uppercase." << endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\n--- String Operations Menu ---\n";
        cout << "1. Concatenate Strings\n";
        cout << "2. Reverse a String\n";
        cout << "3. Delete Vowels\n";
        cout << "4. Sort Strings Alphabetically\n";
        cout << "5. Convert Uppercase to Lowercase\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            concatenateStrings();
            break;
        case 2:
            reverseString();
            break;
        case 3:
            deleteVowels();
            break;
        case 4:
            sortStrings();
            break;
        case 5:
            convertToLowercase();
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}
