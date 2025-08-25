#include<iostream>
using namespace std;
int main(){
    int size;
    cout<<"Enter size of array: ";
    cin>>size;
    int arr[size];
      cout<<"Enter elements of array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    int brr[size][size];
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                // brr[i][j]=arr[i];
                cout<<arr[i];
            }
            else{
                // brr[i][j]=0;
                cout<<"0";
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