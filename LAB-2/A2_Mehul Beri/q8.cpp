#include <iostream>
using namespace std;
int countDistinct(int A[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        bool isDistinct = true;
        for (int j = 0; j < i; j++)
        {
            if (A[i] == A[j])
            {
                isDistinct = false;
                break;
            }
        }
        if (isDistinct)
            count++;
    }
    return count;
}
int main()
{
    int n;
   
    cin >> n;
    int A[n];
  
    for (int i = 0; i < n; i++)
        cin >> A[i];
    int distinct = countDistinct(A, n);
    cout  << distinct << endl;
    return 0;
}