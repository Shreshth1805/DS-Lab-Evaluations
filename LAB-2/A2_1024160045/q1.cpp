#include<iostream>
using namespace std;

int binarySearch(int arr[],int n,int target){
    int start=0, end=n-1;
    while(start<=end){
        int mid=(start+end)/2;
        if (target==arr[mid]) return mid;
        else if(target>arr[mid]) start=mid+1;
        else end=mid-1;
    }
    return -1;
}

int main(){
    int arr[]={-1,0,3,4,5,9,12};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target;
    cout<<"Enter the element to be searched:";
    cin>>target;
    int result=binarySearch(arr,n,target);
    if(result!=-1) cout<<"Element found at index:"<<result<<endl;
    else cout<<"Element not found"<<endl;
    return 0;
}