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
   int unique =0;
   for(int i=0;i<size;i++){
     int count=0;
     
    for(int j=0;j<size;j++){
        if(i!=j && arr[i]!=arr[j]){
            count++;
        }
    }
    if(count == size-1){
unique++;
    }
   }
   cout<<unique;
   
   // 1 2 2 2 2 3 4   size = 7
   // 0 1 2 3 4 5 6   unique=3
    }