#include<iostream>
#include<string>
using namespace std;
// 1 2 3 4 5
// 0 1 2 3 4
int main(){
    // to create an array
    int size;
    int num1,num2,num3,index1,index2;
    string s1="yes";
    string s2="no";
    string s3;
    cout<<"Enter size of array:";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Array created"<<endl;
    // to display an array
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
    cout<<endl;
    // to insert an element
    cout<<"Enter the element: ";
    cin>>num1;
    cout<<"Enter the index: ";
    cin>>index1;
    for(int i=size-1;i>=index1;i--){
        arr[i+1]=arr[i];
    }
    arr[index1]=num1;
    size++;
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
    // to delete an element
    cout<<"Enter the index:";
    cin>>index2;
    for(int i=index2;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    for(int i=0;i<size-1;i++){
        cout<<arr[i];
    }
    // to linear search
    cout<<"Enter number to search: ";
    cin>>num3;
    for(int i=0;i<size;i++){
        if(arr[i]==num3){
           cout<<"Index of element is: "<<i<<endl;
           break;
        }
        if(i==size-1){
cout<<"Number was not found";
        }
    }

    // exit
    cout<<"Are you sure you want to exit: ";
    cin.ignore();
getline(cin,s3);
    if(s3==s2){
        cout<<"Welcome back champ";
    }
    else if(s3==s1){
        cout<<"Have a good dayyy";
    }
    else {
        cout<<"GO PLEASE";
    };
    
}