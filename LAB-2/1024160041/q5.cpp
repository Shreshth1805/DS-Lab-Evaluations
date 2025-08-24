#include <iostream>
using namespace std;
void diagonalMatrix(int n)
{
    int a[n];
    cout << "Enter " << n << " diagonal elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    cout << "\nDiagonal Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                cout << a[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
void triDiagonalMatrix(int n)
{
    int a[3 * n - 2], k = 0;
    cout << "Enter " << 3 * n - 2 << " tri-diagonal elements row-wise:\n";
    for (int i = 0; i < 3 * n - 2; ++i)
        cin >> a[i];
    cout << "\nTri-diagonal Matrix:\n";
    k = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (i - j == -1 || i - j == 0 || i - j == 1)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void upperTriangularMatrix(int n)
{
    int a[n * (n + 1) / 2], k = 0;
    cout << "Enter " << n * (n + 1) / 2 << " upper triangular elements row-wise:\n";
    for (int i = 0; i < n * (n + 1) / 2; ++i)
        cin >> a[i];
    cout << "\nUpper Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void lowerTriangularMatrix(int n)
{
    int a[n * (n + 1) / 2], k = 0;
    cout << "Enter " << n * (n + 1) / 2 << " lower triangular elements row-wise:\n";
    for (int i = 0; i < n * (n + 1) / 2; i++)
        cin >> a[i];
    cout << "\nLower Triangular Matrix:\n";
    k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cout << a[k] << " ";
                k++;
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
void symmetricMatrix(int n)
{
    int a[n * (n + 1) / 2], k = 0;
    cout << "Enter " << n * (n + 1) / 2 << " elements for lower triangle (including diagonal):\n";
    for (int i = 0; i < n * (n + 1) / 2; ++i)
        cin >> a[i];
    cout << "\nSymmetric Matrix:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int index;
            if (i >= j)
            {
                index = (i * (i + 1)) / 2 + j;
            }
            else
            {
                index = (j * (j + 1)) / 2 + i;
            }
            cout << a[index] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int choice, n;
    do
    {
        cout << "\n--- Matrix Menu ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Upper Triangular Matrix\n";
        cout << "4. Lower Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice >= 1 && choice <= 5)
        {
            cout << "Enter size of matrix (n x n): ";
            cin >> n;
        }
        switch (choice)
        {
        case 1:
            diagonalMatrix(n);
            break;
        case 2:
            triDiagonalMatrix(n);
            break;
        case 3:
            upperTriangularMatrix(n);
            break;
        case 4:
            lowerTriangularMatrix(n);
            break;
        case 5:
            symmetricMatrix(n);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);
    return 0;
}