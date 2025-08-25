#include <iostream>
using namespace std;
int Linearsearch(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != i + 1)
            return i + 1;
    }
    return size + 1;
}
int Binarysearch(int arr[], int size)
{
    int left = 0, right = size - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] != mid + 1)
        {
            if (mid == 0 || arr[mid - 1] == mid)
                return mid + 1;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return size + 1;
}
int main()
{
    int n;

    cin >> n;
    int size = n - 1;
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
   
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int Linear = Linearsearch(arr, size);
    int Binary = Binarysearch(arr, size);
    cout  << Linear << endl;
    cout   << Binary << endl;
    return 0;
}