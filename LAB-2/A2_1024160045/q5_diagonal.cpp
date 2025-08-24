#include <iostream>
using namespace std;

class Diagonal {
    int *arr;
    int n;
public:
    Diagonal(int n) {
        this->n = n;
        arr = new int[n];
        for(int i=0;i<n;i++) arr[i]=0;
    }
    void set(int i,int j,int x) {
        if(i==j) arr[i-1]=x;
    }
    int get(int i,int j) {
        if(i==j) return arr[i-1];
        else return 0;
    }
    void display() {
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i==j) cout<<arr[i]<<" ";
                else cout<<"0 ";
            }
            cout<<endl;
        }
    }
};
