#include<iostream>
using namespace std;
// int const MAX= 100;
// int arr[MAX];
// int n= 0;
void rev(){
    int n;
    int arr[n];
    //create
    cout<<"enter the n of the array\n";
    cin>>n;
    cout<<"enter the elements\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }cout<<endl;
    //display
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    
    for(int i=1;i<=(n-1)/2;i++){
        swap(arr[i-1],arr[n-i]);
    }
    cout<<endl;
    cout<<"the reversed array is\n";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
}
int main(){
    rev();
    cout<<endl;
}