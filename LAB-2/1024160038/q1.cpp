#include <iostream>
using namespace std;
int binarySearch(int arr[], int n, int target)
{
    int i = 0;
    int j = n - 1;
    while (i <= j)
    {
        int mid = i + (j - i) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            i = mid + 1;
        else
            j = mid - 1;
    }
    return -1;
}
int main()
{
    int size;
     cin >> size;
    int arr[size];
   for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    int target;
    cin >> target;
    int result = binarySearch(arr, size, target);
    if (result != -1)
        cout << "binary search" << result << endl;
    else
        cout << "not found" << endl;
    return 0;
}