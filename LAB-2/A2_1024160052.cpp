#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2; 
        if (arr[mid] == key) {
            return mid;  
        }
        else if (arr[mid] < key) {
            low = mid + 1; 
        }
        else {
            high = mid - 1; 
        }
    }
    return -1; 
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key;

    cout << "Enter element to search: ";
    cin >> key;

    int result = binarySearch(arr, n, key);

    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found." << endl;

    return 0;
}

//Q2 (Code the Bubble sort with the following elements: {64 34 25 12 22 11 90})

#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n-1 ; i++) {
        for (int j = 0; j < n-i-1 ; j++) {
            if (arr[j] > arr[ j+1 ]) {
                
                int temp = arr[j];
                arr[j] = arr[ j+1 ];
                arr[ j+1 ] = temp;
            }
        }
    }
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Q3 (Design the Logic to Find a Missing Number in a Sorted Array.
// Given an array of n-1 distinct integers in the range of 1 to n,find the missing number in it in a Sorted Array 
// (a) Linear time

#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;

    cout << "Missing number (Linear): " << findMissingLinear(arr, n) << endl;
    return 0;
}

// (b) Using binary search.

#include <iostream>
using namespace std;

int findMissingBinary(int arr[], int n) {
    int low = 0, high = n - 2;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == mid + 1) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low + 1;
}

int main() {
    int arr[] = {1, 2, 3, 5, 6};
    int n = 6;

    cout << "Missing number (Binary Search): " << findMissingBinary(arr, n) << endl;
    return 0;
}

// Q4 String Related Programs
//(a) Write a program to concatenate one string to another string.
#include <iostream>
using namespace std;

int main() {
    string s1 = "Hello ", s2 = "World!";
    s1 += s2;
    cout << "Concatenated string: " << s1 << endl;
    return 0;
}

//(b) Write a program to reverse a string.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string s = "Hello";
    reverse(s.begin(), s.end());
    cout << "Reversed string: " << s << endl;
    return 0;
}

//(c) Write a program to delete all the vowels from the string.
#include <iostream>
using namespace std;

int main() {
    string s = "Beautiful";
    string result = "";

    for (char c : s) {
        if (!(c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
              c=='A'||c=='E'||c=='I'||c=='O'||c=='U')) {
            result += c;
        }
    }

    cout << "String without vowels: " << result << endl;
    return 0;
}

//(d) Write a program to sort the strings in alphabetical order.
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    string arr[] = {"Banana", "Apple", "Mango", "Cherry"};
    int n = 4;

    sort(arr, arr + n);

    cout << "Sorted strings: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}

//(e) Write a program to convert a character from uppercase to lowercase.
#include <iostream>
#include <cctype>
using namespace std;

int main() {
    char c = 'A';
    cout << "Lowercase: " << char(tolower(c)) << endl;
    return 0;
}

// Q5  Assuming array is used to store elements of the following matrices, implement an efficient way that reduces the space requirement.
// (a) Diagonal Matrix.
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int diag[] = {1, 2, 3, 4};

    cout << "Diagonal Matrix:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}

// (b) Tri-diagonal Matrix.
#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int tri[] = {1,2,3,4, 5,6,7, 8,9};

    cout << "Tridiagonal Matrix:" << endl;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << tri[i] << " ";             
            else if (i == j+1) cout << tri[n + j] << " ";
            else if (j == i+1) cout << tri[2*n - 1 + i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}

// (c) Lower triangular Matrix.
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int lower[] = {1,2,3,4,5,6};

    cout << "Lower Triangular Matrix:" << endl;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << lower[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}

// (d) Upper triangular Matrix.
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int upper[] = {1,2,3,4,5,6}; 

    cout << "Upper Triangular Matrix:" << endl;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i <= j) cout << upper[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}

// (e) Symmetric Matrix
#include <iostream>
using namespace std;

int main() {
    int n = 3;
    int sym[] = {1,2,3,4,5,6}; 

    cout << "Symmetric Matrix:" << endl;
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= j) cout << sym[k++] << " ";  
            else cout << sym[(j*(j+1))/2 + i] << " "; 
        }
        cout << endl;
    }
    return 0;
}

// Q6 Write a program to implement the following operations on a Sparse Matrix, assuming the matrix is represented using a triplet.
// (a) Transpose of a matrix.
// (b) Addition of two matrices.
// (c) Multiplication of two matrices.

#include <iostream>
using namespace std;
//(a)
void transpose(int A[][3], int n) {
    cout << "Transpose (triplet):\n";
    cout << A[0][1] << " " << A[0][0] << " " << A[0][2] << endl;
    for (int i = 0; i < A[0][1]; i++) { 
        for (int j = 1; j <= A[0][2]; j++) {
            if (A[j][1] == i)
                cout << A[j][1] << " " << A[j][0] << " " << A[j][2] << endl;
        }
    }
}

//(b)
void add(int A[][3], int B[][3]) {
    cout << "Addition (triplet):\n";
    if (A[0][0] != B[0][0] || A[0][1] != B[0][1]) {
        cout << "Not possible\n"; return;
    }
    cout << A[0][0] << " " << A[0][1] << " ";
    int i=1, j=1, count=0;
    while (i<=A[0][2] && j<=B[0][2]) {
        if (A[i][0]==B[j][0] && A[i][1]==B[j][1]) {
            cout << "\n" << A[i][0] << " " << A[i][1] << " " << A[i][2]+B[j][2];
            i++; j++; count++;
        } else if (A[i][0]<B[j][0] || (A[i][0]==B[j][0] && A[i][1]<B[j][1])) {
            cout << "\n" << A[i][0] << " " << A[i][1] << " " << A[i][2];
            i++; count++;
        } else {
            cout << "\n" << B[j][0] << " " << B[j][1] << " " << B[j][2];
            j++; count++;
        }
    }
    while (i<=A[0][2]) { cout << "\n" << A[i][0] << " " << A[i][1] << " " << A[i][2]; i++; count++; }
    while (j<=B[0][2]) { cout << "\n" << B[j][0] << " " << B[j][1] << " " << B[j][2]; j++; count++; }
    cout << "\nTotal non-zeros = " << count << endl;
}

//(c)
void multiply(int A[][3], int B[][3]) {
    cout << "Multiplication (triplet):\n";
    if (A[0][1] != B[0][0]) {
        cout << "Not possible\n"; return;
    }
  
    int rows=A[0][0], cols=B[0][1];
    int res[rows][cols];
    for(int i=0;i<rows;i++) for(int j=0;j<cols;j++) res[i][j]=0;

    for(int i=1;i<=A[0][2];i++) {
        for(int j=1;j<=B[0][2];j++) {
            if(A[i][1]==B[j][0])
                res[A[i][0]][B[j][1]] += A[i][2]*B[j][2];
        }
    }

    int count=0;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(res[i][j]!=0) count++;
    cout<<rows<<" "<<cols<<" "<<count<<endl;
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            if(res[i][j]!=0) cout<<i<<" "<<j<<" "<<res[i][j]<<endl;
}

int main() {
  
    int A[4][3]={{3,3,3},{0,2,3},{1,0,4},{2,1,5}};
    int B[4][3]={{3,3,3},{0,0,1},{1,1,2},{2,2,3}};

    transpose(A,3);
    cout << endl;
    add(A,B);
    cout << endl;
    multiply(A,B);
    return 0;
}

// Q7 Let A[1 …. n] be an array of n real numbers. A pair (A[i], A[j ]) is said to be an inversion if these numbers are out of order, i.e., i < j but A[i]>A[j ]. 
// Write a program to count the number of inversions in an array.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr)/sizeof(arr[0]), inv = 0;

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(arr[i]>arr[j]) inv++;

    cout << "Total Inversions = " << inv << endl;
    return 0;
}

// Q8 Write a program to count the total number of distinct elements in an array of length n.

#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 2, 2, 3, 4, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int count = 0;

    for(int i=0; i<n; i++) {
        bool isDuplicate = false;
        for(int j=0; j<i; j++) {
            if(arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if(!isDuplicate)
          count++;
    }

    cout << "Total distinct elements = " << count << endl;
    return 0;