#include<iostream>

using namespace std;


int main (){
    int i,low,high,mid,target,j,n;
    cout << "What is the legnth of the array ";
	cin >> n;
	int arr[n];
	cout << "Tell us the elements of array ";
	for(i=0; i<n; i++) {
		cout<<i+1<<" ";
		cin>>arr[i];
	}
	cout<<"Your array is ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    int k=0;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            k++;
        }
    }
    cout<<"\nThe number of inversions in the array is "<<k<<endl;
    system("pause");
}