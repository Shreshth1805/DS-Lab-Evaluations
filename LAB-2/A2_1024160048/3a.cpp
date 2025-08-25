#include<iostream>
using namespace std;
int linearsearch(int arr[],int size){
    for(int i=0;i<size;i++){
        if(arr[i]==i+1){
            continue;
        }
        else if(arr[i]!=i+1){
            return i+1;
        }
    }
    return -1;
}


// int sumfinder(int arr[],int n,int size){
//     int original_sum=n*(n+1)/2;
//     int new_sum=0;
//     for(int i=0;i<size;i++){
//         new_sum=new_sum+arr[i];
//     }
//     int missing_num=original_sum-new_sum;
//     return missing_num;
// }


int main(){
    int n,size,k;
    cout<<"Enter numbers size: ";
    cin>>n;
    size=n-1;
    int arr[size];
    cout<<"Enter elements: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
cout<<linearsearch(arr,size);
// cout<<sumfinder(arr,n,size);
}