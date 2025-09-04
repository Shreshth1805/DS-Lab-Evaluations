#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int n=3*size-2;
    int arr[n];
      cout<<"Enter elements of array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i-j==1||i-j==-1||i-j==0){
                // brr[i][j]=arr[i];
                cout<<arr[k]<<" ";
                k++;
            }
            else{
                // brr[i][j]=0;
                cout<<"0"<<" ";
            }    
        }
        cout<<endl;
    }
    // for(int i=0;i<size;i++){
    //     for(int j=0;j<size;j++){
    //         cout<<brr[i][j];
    //     }
    //     cout<<endl;
    }