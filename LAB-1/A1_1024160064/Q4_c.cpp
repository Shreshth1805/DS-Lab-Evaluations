#include<iostream>
using namespace std;
void transposeMatrix() {
    int r, c;
    cin >> r >> c;
    int A[10][10];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++) cin >> A[i][j];
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {cout << A[j][i] << " ";}
        cout<<endl;
    }
}
int main(){
    transposeMatrix();
    cout<<endl;
}