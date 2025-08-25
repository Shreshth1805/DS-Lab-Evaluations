#include<iostream>
using namespace std;

class TriDiagonal {
    int *arr;
    int n;
public:
    TriDiagonal(int n) {
        this->n = n;
        arr = new int[3*n-2];
        for(int i=0; i<3*n-2; i++) arr[i]=0;
    }
    void set(int i,int j,int x) {
        if(i-j==1) arr[i-2] = x;           
        else if(i==j) arr[n-1+i-1] = x;    
        else if(j-i==1) arr[2*n-1+i-1] = x; 
    }
    int get(int i,int j) {
        if(i-j==1) return arr[i-2];
        else if(i==j) return arr[n-1+i-1];
        else if(j-i==1) return arr[2*n-1+i-1];
        return 0;
    }
    void display() {
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                cout << get(i,j) << " ";
            }
            cout << endl;
        }
    }
};