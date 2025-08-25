#include <iostream>
using namespace std;
struct Triplet
{
    int row, col, val;
};
void inputSparse(Triplet mat[], int n)
{
    cout << "Enter " << n << " triplets (row col value):\n";
    for (int i = 0; i < n; i++)
        cin >> mat[i].row >> mat[i].col >> mat[i].val;
}
void displaySparse(Triplet mat[], int n)
{
    cout << "\nSparse Matrix (Triplet Form):\n";
    cout << "Row Col Val\n";
    for (int i = 0; i < n; i++)
        cout << mat[i].row << "   " << mat[i].col << "   " << mat[i].val << endl;
}
void transposeSparse(Triplet mat[], Triplet result[], int n)
{
    for (int i = 0; i < n; i++)
    {
        result[i].row = mat[i].col;
        result[i].col = mat[i].row;
        result[i].val = mat[i].val;
    }
}
int addSparse(Triplet A[], int n1, Triplet B[], int n2, Triplet result[])
{
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2)
    {
        if (A[i].row == B[j].row && A[i].col == B[j].col)
        {
            result[k] = A[i];
            result[k].val += B[j].val;
            ++i;
            ++j;
            ++k;
        }
        else if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col))
        {
            result[k++] = A[i++];
        }
        else
        {
            result[k++] = B[j++];
        }
    }
    while (i < n1)
        result[k++] = A[i++];
    while (j < n2)
        result[k++] = B[j++];
    return k;
}
int multiplySparse(Triplet A[], int n1, Triplet B[], int n2, Triplet result[])
{
    Triplet B_T[n2];
    for (int i = 0; i < n2; ++i)
    {
        B_T[i].row = B[i].col;
        B_T[i].col = B[i].row;
        B_T[i].val = B[i].val;
    }
    int k = 0;
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            if (A[i].col == B_T[j].col)
            {
                int r = A[i].row;
                int c = B_T[j].row;
                int v = A[i].val * B_T[j].val;
                bool found = false;
                for (int x = 0; x < k; ++x)
                {
                    if (result[x].row == r && result[x].col == c)
                    {
                        result[x].val += v;
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    result[k].row = r;
                    result[k].col = c;
                    result[k].val = v;
                    ++k;
                }
            }
        }
    }
    return k;
}
int main()
{
    const int MAX_SIZE = 100;
    Triplet A[MAX_SIZE], B[MAX_SIZE], result[MAX_SIZE];
    int choice, n1 = 0, n2 = 0;
    do
    {
        cout << "\n--- Sparse Matrix Operations ---\n";
        cout << "1. Transpose\n";
        cout << "2. Addition\n";
        cout << "3. Multiplication\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            cout << "Enter number of non-zero elements: ";
            cin >> n1;
            inputSparse(A, n1);
            transposeSparse(A, result, n1);
            displaySparse(result, n1);
        }
        else if (choice == 2 || choice == 3)
        {
            
            cin >> n1;
            inputSparse(A, n1);
            
            cin >> n2;
            inputSparse(B, n2);
            int nR = 0;
            if (choice == 2)
                nR = addSparse(A, n1, B, n2, result);
            else
                nR = multiplySparse(A, n1, B, n2, result);
            displaySparse(result, nR);
        }
        else if (choice == 0)
        {
            cout << "Exiting program.\n";
        }
        else
        {
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}