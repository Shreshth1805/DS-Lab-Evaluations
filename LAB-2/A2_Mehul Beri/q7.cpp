#include <iostream>
using namespace std;
void updateBIT(int BIT[], int index, int size) {
    while (index <= size) {
        BIT[index]++;
        index += index & -index;
    }
}
int queryBIT(int BIT[], int index) {
    int sum = 0;
    while (index > 0) {
        sum += BIT[index];
        index -= index & -index;
    }
    return sum;
}
void compress(int A[], int compressed[], int n) {
    int temp[n];
    for (int i = 0; i < n; ++i)
        temp[i] = A[i];
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (temp[j] > temp[j + 1]) {
                int t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
    int unique[n], u = 0;
    unique[u++] = temp[0];
    for (int i = 1; i < n; ++i)
        if (temp[i] != temp[i - 1])
            unique[u++] = temp[i];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < u; ++j)
            if (A[i] == unique[j]) {
                compressed[i] = j + 1;
                break;
            }
}
int countInversionsFenwick(int A[], int n) {
    int compressed[n];
    compress(A, compressed, n);
    int BIT[n + 1];
    for (int i = 0; i <= n; ++i)
        BIT[i] = 0;
    int invCount = 0;
    for (int i = n - 1; i >= 0; --i) {
        invCount += queryBIT(BIT, compressed[i] - 1);
        updateBIT(BIT, compressed[i], n);
    }
    return invCount;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int A[n];
    cout << "Enter array elements:\n";
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    int totalInversions = countInversionsFenwick(A, n);
    cout << "Number of inversions: " << totalInversions << endl;
    return 0;
}