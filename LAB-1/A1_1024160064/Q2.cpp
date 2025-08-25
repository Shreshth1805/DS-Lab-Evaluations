
#include<iostream>
using namespace std;
const int MAX=  100;
int arr[MAX];
int arrsize=0;
void create(){
    cout<<"enter the arrsize of the array\n";
    cin>>arrsize;
    cout<<"enter the elements\n";
    for(int i=0;i<arrsize;i++){
        cin>>arr[i];
    }
}
void display(){
    cout<<endl<<"the array is\n";
    for(int i=0;i<arrsize;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void merge(int arr[],int low,int mid,int high){
    int temp[MAX];
    int left= low;
    int right= mid +1;
    int i=0;
    while(left<=mid && right<= high){
        if(arr[left]<=arr[right]){
                temp[i]= arr[left];
                left++;
            }
        else{
            temp[i]= arr[right];
            right++;
        }
        i++;
    }
    while(left<=mid){
        temp[i]= arr[left];
        left++;
        i++;
    }
    while(right<=high){
        temp[i]= arr[right];
        right++;
        i++;
    }
    for(int j=low;j<=high;j++){
        arr[j]= temp[j-low];
    }
}
void merge_sort(int arr[],int low, int high){
    if(low == high){
        return;
    }
    if(low<high){
    int mid= low + (high-low)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
    }
}
void rm_dup(){
    create();
    display();
    // first sort the array by merge sort
    merge_sort(arr,0,arrsize-1);
    cout<<"sorted array";
    display();
    merge(arr,arr[0],arr[(0+arrsize)/2],arr[arrsize]);
    int j=0;
    for(int i=0;i<arrsize-1;i++){
        if(arr[i]!=arr[i+1]){
            arr[j]=arr[i];
            j++;
        }
    }
    arr[j] = arr[arrsize -1];
    j++;
    arrsize= j;
    cout<<"Array after removing the duplicates\n";
    display();
}
int main(){
rm_dup();
cout<<endl;
return 0;
}