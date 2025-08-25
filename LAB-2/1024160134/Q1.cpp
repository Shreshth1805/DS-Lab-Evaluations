#include<iostream>
using namespace std;

int BinarySearch(int arr[] ,int n,int key){
    int low=0,high=n-1;
    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid]==key) return mid+
        1;

        else if(arr[mid]<key) low = mid +1;

        else high = mid - 1;
    }
    return -1;
}

int main(){
    int n,key;
    cout<<"Entre number of Elements :"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Entre "<<n<< " elements: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Entre Number to find: ";
    cin>>key;
    int result = BinarySearch(arr,n,key);

    if(result != -1) cout<<"Element found at "<<result<<endl;
    else cout<<"Element not found";
}