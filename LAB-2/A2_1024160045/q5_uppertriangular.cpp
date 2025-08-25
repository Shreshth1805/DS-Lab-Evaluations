#include<iostream>
using namespace std;

class UpperTriangular {
    int *arr;
    int n;
public:
    UpperTriangular(int n) {
        this->n = n;
        arr = new int[n*(n+1)/2];
        for(int i=0;i<n*(n+1)/2;i++) arr[i]=0;
    }
    void set(int i,int j,int x) {
        if(i<=j) arr[(i-1)*n - (i-2)*(i-1)/2 + (j-i)] = x;
    }
    int get(int i,int j) {
        if(i<=j) return arr[(i-1)*n - (i-2)*(i-1)/2 + (j-i)];
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