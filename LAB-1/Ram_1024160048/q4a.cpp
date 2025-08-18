#include<iostream>
#include<algorithm>
using namespace std;
// array     -> 1 2 3 4 5
// rev array -> 5 4 3 2 1
// indexes   -> 0 1 2 3 4
void reverse(int arr[],int size){
    if(size%2==0){
        for(int i=0;i<size-1;i++){
        swap(arr[i],arr[size-1-i]);
    }
    }
     else if(size%2!=0){
        for(int i=0;i<(size+1)/2;i++){
        swap(arr[i],arr[size-1-i]);
    }
    }
}

int main(){
// to create an array
    int size;
    cout<<"Enter size of array:";
    cin>>size;
    int arr[size];
    cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"Array created"<<endl;
    reverse(arr,size);
    cout<<"Reversed Array is: ";
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
}
    