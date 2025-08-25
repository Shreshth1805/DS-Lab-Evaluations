#include<iostream>
#include<algorithm>
using namespace std;
void bubblesort(int arr[],int size){
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
int main(){
    int size,k;
    cout<<"Enter size: ";
    cin>>size;
    int arr[size];
    cout<<"Enter elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    bubblesort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i];
    }
}