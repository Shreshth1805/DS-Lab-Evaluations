#include<iostream>
using namespace std;
int binarysearch(int arr[],int size,int l,int r,int k){
int m;
while(l<=r) {
     m = (l+r)/2;
    if(arr[m]==k){
        return m;
    }
    else if(arr[m]<k){
       return binarysearch(arr,size,m+1,r,k);
    }
    else{
        return binarysearch(arr,size,l,m-1,k);
    }
    return -1;
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
cout<<"Enter element to search: ";
cin>>k;
cout<<binarysearch(arr,size,0,size-1,k);
}