#include<iostream>
#include<iomanip>
using namespace std;
const int MAX_SIZE=100;
void multi_matrix(){
    int n;
    cout<<"enter the size= n*n of both arrays\n";
    cin>>n;
    int i,j;
    int A[MAX_SIZE][MAX_SIZE],B[MAX_SIZE][MAX_SIZE],C[MAX_SIZE][MAX_SIZE];
    cout<<"enter the elements of A matrix\n";
    for(i=0;i<n;i++){
        for( j=0;j<n;j++){
            cin>>A[i][j];
        }
    }
    cout<<"enter the elements of B matrix\n";
        for(i=0;i<n;i++){
            for( j=0;j<n;j++){
            cin>>B[i][j];
            }
        }
    cout<<endl;

    for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
            int sum=0;
            for(int k=0;k<n;k++){
                sum= sum+ A[i][k]*B[k][j];
                C[i][j]=sum;
            }
        }
    }
    //display C[i][j]
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    multi_matrix();
    cout<<endl;

}