#include<iostream>
#include<string>
using namespace std;

// Q1 Binary Search
void binarySearch() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[100];
    cout << "Enter sorted array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int target;
    cout << "Enter element to search: ";
    cin >> target;
    
    int left = 0, right = n - 1, found = -1;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == target) {
            found = mid;
            break;
        }
        else if(arr[mid] < target) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    if(found != -1) {
        cout << "Element found at index " << found << endl;
    }
    else {
        cout << "Element not found" << endl;
    }
}

// Q2: Bubble Sort
void bubbleSort() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    
    cout << "Original array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Q3a: Missing Number - Linear Time
void missingNumberLinear() {
    int n;
    cout << "Enter n (array should contain n-1 elements from 1 to n): ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n-1 << " sorted elements: ";
    for(int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    
    int sum = n * (n + 1) / 2;
    int arraySum = 0;
    for(int i = 0; i < n-1; i++) {
        arraySum += arr[i];
    }
    
    cout << "Missing number: " << sum - arraySum << endl;
}

// Q3b: Missing Number - Binary Search
void missingNumberBinary() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    int arr[100];
    cout << "Enter " << n-1 << " sorted elements: ";
    for(int i = 0; i < n-1; i++) {
        cin >> arr[i];
    }
    
    int left = 0, right = n - 2;
    while(left <= right) {
        int mid = (left + right) / 2;
        if(arr[mid] == mid + 1) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    
    cout << "Missing number: " << left + 1 << endl;
}

// Q4a: String Concatenation
void stringConcatenate() {
    string str1, str2;
    cout << "Enter first string: ";
    cin >> str1;
    cout << "Enter second string: ";
    cin >> str2;
    
    string result = str1 + str2;
    cout << "Concatenated string: " << result << endl;
}

// Q4b: String Reverse
void stringReverse() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    
    string reversed = "";
    for(int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    
    cout << "Reversed string: " << reversed << endl;
}

// Q4c: Delete Vowels
void deleteVowels() {
    string str;
    cout << "Enter string: ";
    cin >> str;
    
    string result = "";
    for(int i = 0; i < str.length(); i++) {
        char c = str[i];
        if(c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u' && 
           c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U') {
            result += c;
        }
    }
    
    cout << "String without vowels: " << result << endl;
}

// Q4d: Sort Strings
void sortStrings() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    string arr[100];
    
    cout << "Enter strings: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    
    cout << "Sorted strings: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Q4e: Uppercase to Lowercase
void upperToLower() {
    char c;
    cout << "Enter uppercase character: ";
    cin >> c;
    
    if(c >= 'A' && c <= 'Z') {
        c = c + 32;
        cout << "Lowercase: " << c << endl;
    }
    else {
        cout << "Not an uppercase character" << endl;
    }
}

// Q5a: Diagonal Matrix
void diagonalMatrix() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    int diagonal[100];
    
    cout << "Enter diagonal elements: ";
    for(int i = 0; i < n; i++) {
        cin >> diagonal[i];
    }
    
    cout << "Matrix representation:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                cout << diagonal[i] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Q5b: Tridiagonal Matrix
void tridiagonalMatrix() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int lower[100], main[100], upper[100];
    
    cout << "Enter lower diagonal: ";
    for(int i = 0; i < n-1; i++) {
        cin >> lower[i];
    }
    
    cout << "Enter main diagonal: ";
    for(int i = 0; i < n; i++) {
        cin >> main[i];
    }
    
    cout << "Enter upper diagonal: ";
    for(int i = 0; i < n-1; i++) {
        cin >> upper[i];
    }
    
    cout << "Matrix representation:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) {
                cout << main[i] << " ";
            }
            else if(i == j + 1) {
                cout << lower[j] << " ";
            }
            else if(i == j - 1) {
                cout << upper[i] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Q5c: Lower Triangular Matrix
void lowerTriangular() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int lower[100];
    int k = 0;
    
    cout << "Enter lower triangular elements row by row: ";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            cin >> lower[k++];
        }
    }
    
    cout << "Matrix representation:" << endl;
    k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i >= j) {
                cout << lower[k++] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Q5d: Upper Triangular Matrix
void upperTriangular() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int upper[100];
    int k = 0;
    
    cout << "Enter upper triangular elements row by row: ";
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cin >> upper[k++];
        }
    }
    
    cout << "Matrix representation:" << endl;
    k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) {
                cout << upper[k++] << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

// Q5e: Symmetric Matrix
void symmetricMatrix() {
    int n;
    cout << "Enter size of matrix: ";
    cin >> n;
    int upper[100];
    int k = 0;
    
    cout << "Enter upper triangular elements: ";
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            cin >> upper[k++];
        }
    }
    
    cout << "Symmetric Matrix:" << endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i <= j) {
                k = (i * (2 * n - i + 1)) / 2 + (j - i);
                cout << upper[k] << " ";
            }
            else {
                k = (j * (2 * n - j + 1)) / 2 + (i - j);
                cout << upper[k] << " ";
            }
        }
        cout << endl;
    }
}

// Q6a: Sparse Matrix Transpose
void sparseTranspose() {
    int rows, cols, nonZero;
    cout << "Enter rows, columns, non-zero elements: ";
    cin >> rows >> cols >> nonZero;
    
    int sparse[100][3], transpose[100][3];
    
    cout << "Enter sparse matrix (row, col, value):" << endl;
    for(int i = 0; i < nonZero; i++) {
        cin >> sparse[i][0] >> sparse[i][1] >> sparse[i][2];
    }
    
    for(int i = 0; i < nonZero; i++) {
        transpose[i][0] = sparse[i][1];
        transpose[i][1] = sparse[i][0];
        transpose[i][2] = sparse[i][2];
    }
    
    cout << "Transpose (row, col, value):" << endl;
    for(int i = 0; i < nonZero; i++) {
        cout << transpose[i][0] << " " << transpose[i][1] << " " << transpose[i][2] << endl;
    }
}

// Q7: Count Inversions
void countInversions() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[100];
    
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int count = 0;
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                count++;
            }
        }
    }
    
    cout << "Number of inversions: " << count << endl;
}

// Q8: Count Distinct Elements
void countDistinct() {
    int n;
    cout << "Enter array size: ";
    cin >> n;
    int arr[100];
    
    cout << "Enter array elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int distinct = 0;
    for(int i = 0; i < n; i++) {
        bool isDistinct = true;
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        if(isDistinct) {
            distinct++;
        }
    }
    
    cout << "Number of distinct elements: " << distinct << endl;
}
int main() {
    int choice;
    
    while(true) {
        cout << "\n=== LAB ASSIGNMENT 2 MENU ===" << endl;
        cout << "1. Binary Search" << endl;
        cout << "2. Bubble Sort" << endl;
        cout << "3. Missing Number - Linear" << endl;
        cout << "4. Missing Number - Binary Search" << endl;
        cout << "5. String Concatenation" << endl;
        cout << "6. String Reverse" << endl;
        cout << "7. Delete Vowels" << endl;
        cout << "8. Sort Strings" << endl;
        cout << "9. Uppercase to Lowercase" << endl;
        cout << "10. Diagonal Matrix" << endl;
        cout << "11. Tridiagonal Matrix" << endl;
        cout << "12. Lower Triangular Matrix" << endl;
        cout << "13. Upper Triangular Matrix" << endl;
        cout << "14. Symmetric Matrix" << endl;
        cout << "15. Sparse Matrix Transpose" << endl;
        cout << "16. Count Inversions" << endl;
        cout << "17. Count Distinct Elements" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: binarySearch(); break;
            case 2: bubbleSort(); break;
            case 3: missingNumberLinear(); break;
            case 4: missingNumberBinary(); break;
            case 5: stringConcatenate(); break;
            case 6: stringReverse(); break;
            case 7: deleteVowels(); break;
            case 8: sortStrings(); break;
            case 9: upperToLower(); break;
            case 10: diagonalMatrix(); break;
            case 11: tridiagonalMatrix(); break;
            case 12: lowerTriangular(); break;
            case 13: upperTriangular(); break;
            case 14: symmetricMatrix(); break;
            case 15: sparseTranspose(); break;
            case 16: countInversions(); break;
            case 17: countDistinct(); break;        
            case 0: return 0;
            default: cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}