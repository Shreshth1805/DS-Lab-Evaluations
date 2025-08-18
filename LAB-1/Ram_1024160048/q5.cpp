#include<iostream>
using namespace std;

int main(){
    int r1,c1;
    int r_sum=0;
    int c_sum=0;
     cout<<"enter row and column for 1: ";
    cin>>r1>>c1;
    int a[r1][c1];
    cout<<"Enter elements: ";
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c1;j++){
            r_sum=r_sum+a[i][j];
        }
        cout<<"Sum of r"<<i<<" is: "<<r_sum<<" "<<endl;
        r_sum=0;
    }
int b[c1][r1];
for(int i=0;i<c1;i++){
    for(int j=0;j<r1;j++){
        b[i][j]=a[j][i];
    }
}

    for(int i=0;i<c1;i++){
        for(int j=0;j<r1;j++){
            c_sum=c_sum+b[i][j];
        }
        cout<<"Sum of c"<<i<<" is: "<<c_sum<<" "<<endl;
        c_sum=0;
    }
}