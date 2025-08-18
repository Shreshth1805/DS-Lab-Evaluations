#include <iostream>
#include <string>
using namespace std;

int binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid] < x) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}
void bubbleSort(int arr[], int n) {
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int findMissingLinear(int arr[], int n) {
    int total = n*(n+1)/2;
    int sum = 0;
    for(int i=0;i<n-1;i++) sum += arr[i];
    return total - sum;
}

int findMissingBinary(int arr[], int n) {
    int low=0, high=n-2;
    while(low <= high) {
        int mid = (low+high)/2;
        if(arr[mid] == mid+1) low = mid+1;
        else high = mid-1;
    }
    return low+1;
}
void stringPrograms() {
    string s1 = "Hello", s2 = "World";

    cout << "Concat: " << s1+s2 << endl;
    string rev = s1;
    int n = rev.length();
    for(int i=0;i<n/2;i++) {
        char temp = rev[i];
        rev[i] = rev[n-1-i];
        rev[n-1-i] = temp;
    }
    cout << "Reverse: " << rev << endl;
    string str = "Hello World", noVowel="";
    for(int i=0;i<str.length();i++) {
        char ch = tolower(str[i]);
        if(ch!='a' && ch!='e' && ch!='i' && ch!='o' && ch!='u')
            noVowel += str[i];
    }
    cout << "Without vowels: " << noVowel << endl;
    string arr[3] = {"banana","apple","cherry"};
    for(int i=0;i<3;i++) {
        for(int j=i+1;j<3;j++) {
            if(arr[i] > arr[j]) {
                string temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Sorted strings: ";
    for(int i=0;i<3;i++) cout<<arr[i]<<" ";
    cout<<endl;
    char c = 'A';
    if(c >= 'A' && c <= 'Z') c = c + 32;
    cout << "Lowercase of A: " << c << endl;
}

int countInversions(int arr[], int n) {
    int count=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[i] > arr[j]) count++;
        }
    }
    return count;
}

int countDistinct(int arr[], int n) {
    int count=0;
    for(int i=0;i<n;i++) {
        bool isDuplicate=false;
        for(int j=0;j<i;j++) {
            if(arr[i]==arr[j]) {
                isDuplicate=true;
                break;
            }
        }
        if(!isDuplicate) count++;
    }
    return count;
}

int main() {
    int choice;
    do {
        cout << "\n===== MENU =====\n";
        cout << "1. Binary Search\n";
        cout << "2. Bubble Sort\n";
        cout << "3. Missing Number\n";
        cout << "4. String Programs\n";
        cout << "5. Count Inversions\n";
        cout << "6. Count Distinct Elements\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if(choice==1) {
            int arr[] = {1,2,3,4,5,6,7};
            int x; cout<<"Enter element to search: "; cin>>x;
            int idx = binarySearch(arr,7,x);
            if(idx!=-1) cout<<"Found at index "<<idx<<endl;
            else cout<<"Not found"<<endl;
        }
        else if(choice==2) {
            int arr[] = {64,34,25,12,22,11,90};
            int n=7;
            bubbleSort(arr,n);
            cout<<"Sorted: ";
            for(int i=0;i<n;i++) cout<<arr[i]<<" ";
            cout<<endl;
        }
        else if(choice==3) {
            int arr[] = {1,2,3,5};
            cout<<"Missing (Linear): "<<findMissingLinear(arr,5)<<endl;
            cout<<"Missing (Binary): "<<findMissingBinary(arr,5)<<endl;
        }
        else if(choice==4) {
            stringPrograms();
        }
        else if(choice==5) {
            int arr[] = {2,4,1,3,5}, n=5;
            cout<<"Inversions: "<<countInversions(arr,n)<<endl;
        }
        else if(choice==6) {
            int arr[] = {1,2,2,3,4,4,5}, n=7;
            cout<<"Distinct elements: "<<countDistinct(arr,n)<<endl;
        }

    } while(choice!=7);

    cout<<"Exiting program..."<<endl;
    return 0;
}
