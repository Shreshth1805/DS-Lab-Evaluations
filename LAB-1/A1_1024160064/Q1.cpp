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
void insert(){
    int pos, value;
    cout<<"enter the position\n";
    cin>>pos;
    cout<<"\n enter the value\n";
    cin>>value;
    if(pos<0|| pos>arrsize){
        cout<<" Invalid Position\n";
        return;
    }
    for(int i=arrsize-1;i>=pos;i--){
        arr[i+1]= arr[i];
    }
    arr[pos]= value;
    arrsize++;
    cout<<endl;
    display();
}
void discard(){
    int pos;
    cout<<endl;
    cout<<"enter the position\n";
    cin>>pos;
    cout<<endl;
    for(int i=pos;i<arrsize-1;i++){
        arr[i]=arr[i+1];
    }
    arrsize--;
    display();
    cout<<endl;
}
void linear_search(){
    int value;
    cout<<"enter the value\n";
    cin>>value;
    cout<<endl;
    bool found= false;
    for(int i=0;i<arrsize;i++){
        if(arr[i]== value){
            cout<<"the "<<value<<" is found at index "<<i<<endl;
            found= true;
            break;
        }
    }
    if(!found){
        cout<<"the value is not present in the array\n";
    }
    cout<<endl;
}
void EXIT(){
        cout<<"the program is exited\n";
        exit(0);   
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
    while(true){
    cout<<"***********************************MENU************************************\n";
    cout<<"                 1- CREATE\n";
    cout<<"                 2- DISPLAY\n";
    cout<<"                 3- INSERT\n";
    cout<<"                 4- DISCARD\n";
    cout<<"                 5- LINEAR SEARCH\n";
    cout<<"                 6- EXIT\n";
    cout<<"                 7- REMOVE DUPLICATES\n";
    int option;
    cout<<"\n\n Enter the serial no. of the function you want to perform\n\n";
    cin>>option;
    cout<<endl;
    switch (option){
        case 1:create();break;
        case 2:display();break;
        case 3:insert();break;
        case 4:discard();break;
        case 5:linear_search();break;
        case 6:EXIT();break;
        case 7:rm_dup();break;
        default: cout<<"INVALID OPTION\n";
    }
}
    return 0;
}
