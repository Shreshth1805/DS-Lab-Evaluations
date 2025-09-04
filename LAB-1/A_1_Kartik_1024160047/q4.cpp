#include <iostream>
using namespace std;

int main(){
    //Reversing an array
    int n=5;
    int arr[n]={1,2,3,4,5};
    for(int i=n-1;i>=0;i--){
        cout << arr[i];

              int A[2][2] = { {1, 2}, {3, 4} };
              int B[2][2] = { {5, 6}, {7, 8} };
              int C[2][2] = {0};
    //Multiplication of array
   
     for (int i = 0; i < 2; i++) {
         for (int j = 0; j < 2; j++) {
             for (int k = 0; k < 2; k++) {
                 C[i][j] += A[i][k] * B[k][j];
             }
         }
     }

    // // Output 
    cout << "Result Matrix:\n";
     for (int i = 0; i < 2; i++) {   
          for (int j = 0; j < 2; j++) {  
                   cout << C[i][j] << " ";     } 
                       cout << endl; }    

    }
    //Transpose Matrix
      int A[2][3] = { {1, 2, 3}, {4, 5, 6} };
     int T[3][2];
   
     for (int i = 0; i < 2; i++) {
         for (int j = 0; j < 3; j++) {
           T[j][i] = A[i][j];
         }
     }

    
     cout << "Transpose Matrix:\n";
     for (int i = 0; i < 3; i++) {
         for (int j = 0; j < 2; j++) {
             cout << T[i][j] << " ";
         }
         cout << endl;
     }
    return 0;
}