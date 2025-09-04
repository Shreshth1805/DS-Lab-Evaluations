Q-1
#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    return -1;
}
int main()
{
    int size;
     cin >> size;
    int arr[size];
   for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "binary search" << result << endl;
    else
        cout << "not found" << endl;
    return 0;
}




Q-2
#include <iostream>
using namespace std;

void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, size);
    printArray(arr, size);
    return 0;
}

Q-3
#include <iostream>
using namespace std;
int Linearsearch(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return size + 1;
}
int Binarysearch(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] != mid + 1)
        {
            if (mid == 0 || arr[mid - 1] == mid)
                return mid + 1;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return size + 1;
}
int main()
{
    int n;

    cin >> n;
    int size = n - 1;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
   
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int Linear = Linearsearch(arr, size);
    int Binary = Binarysearch(arr, size);
    cout  << Linear << endl;
    cout   << Binary << endl;
    return 0;
}

Q-4
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


Q-5
#include <iostream>
using namespace std;
void diagonalMatrix(int n)
{
    int a[n];
    cout << "Enter " << n << " diagonal elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << a[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
void triDiagonalMatrix(int n)
{
    int a[3 * n - 2], k = 0;
    cout << "Enter " << 3 * n - 2 << " tri-diagonal elements row-wise:\n";
    for (int i = 0; i < 3 * n - 2; ++i)
        cin >> a[i];
    cout << "\nTri-diagonal Matrix:\n";
    k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i - j == -1 || i - j == 0 || i - j == 1)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void upperTriangularMatrix(int n)
{
    int a[n * (n + 1) / 2], k = 0;
    cout << "Enter " << n * (n + 1) / 2 << " upper triangular elements row-wise:\n";
    for (int i = 0; i < n * (n + 1) / 2; ++i)
        cin >> a[i];
    cout << "\nUpper Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void lowerTriangularMatrix(int n)
{
    int a[n * (n + 1) / 2], k = 0;
    cout << "Enter " << n * (n + 1) / 2 << " lower triangular elements row-wise:\n";
    for (int i = 0; i < n * (n + 1) / 2; i++)
        cin >> a[i];
    cout << "\nLower Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void symmetricMatrix(int n)
{
    int a[n * (n + 1) / 2], k = 0;
    cout << "Enter " << n * (n + 1) / 2 << " elements for lower triangle (including diagonal):\n";
    for (int i = 0; i < n * (n + 1) / 2; ++i)
        cin >> a[i];
    cout << "\nSymmetric Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int index;
            if (i >= j)
            {
                index = (i * (i + 1)) / 2 + j;
            }
            else
            {
                index = (j * (j + 1)) / 2 + i;
            }
            cout << a[index] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int choice, n;
    do
    {
        cout << "\n--- Matrix Menu ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Upper Triangular Matrix\n";
        cout << "4. Lower Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter size of matrix (n x n): ";
            cin >> n;
        }
        switch (choice)
        {
        case 1:
            diagonalMatrix(n);
            break;
        case 2:
            triDiagonalMatrix(n);
            break;
        case 3:
            upperTriangularMatrix(n);
            break;
        case 4:
            lowerTriangularMatrix(n);
            break;
        case 5:
            symmetricMatrix(n);
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

Q-6
#include <iostream>
using namespace std;
void updateBIT(int BIT[], int index, int size) {
    while (index <= size) {
        BIT[index]++;
        index += index & -index;
    }
}
int queryBIT(int BIT[], int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}
void compress(int A[], int compressed[], int n) {
    int temp[n];
    for (int i = 0; i < n; ++i)
        temp[i] = A[i];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
    int unique[n], u = 0;
    unique[u++] = temp[0];
    for (int i = 1; i < n; ++i)
        if (temp[i] != temp[i - 1])
            unique[u++] = temp[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < u; ++j)
            if (A[i] == unique[j]) {
                compressed[i] = j + 1;
                break;
            }
}
int countInversionsFenwick(int A[], int n) {
    int compressed[n];
    compress(A, compressed, n);
    int BIT[n + 1];
    for (int i = 0; i <= n; ++i)
        BIT[i] = 0;
    int invCount = 0;
    for (int i = n - 1; i >= 0; --i) {
        invCount += queryBIT(BIT, compressed[i] - 1);
        updateBIT(BIT, compressed[i], n);
    }
    return invCount;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    int totalInversions = countInversionsFenwick(A, n);
    cout << "Number of inversions: " << totalInversions << endl;
    return 0;

Q-8
#include <iostream>
using namespace std;
int countDistinct(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool isDistinct = true;
        for (int j = 0; j < i; j++)
        {
            if (A[i] == A[j])
            {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct)
            count++;
    }
    return count;
}
int main()
{
    int n;
   
    cin >> n;
    int A[n];
  
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int distinct = countDistinct(A, n);
    cout  << distinct << endl;
    return 0;
}
}
