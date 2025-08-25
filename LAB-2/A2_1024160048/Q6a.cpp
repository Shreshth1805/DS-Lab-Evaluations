#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int row, column, nf_values;
    cout << "Enter no of rows,column,values";
    cin >> row >> column >> nf_values;
    vector<vector<int>> triplet;
    cout << "Enter row,calumn,value for each element";
    for (int i = 0; i < nf_values; i++)
    {
        int r, c, v;
        cin >> r >> c >> v;
        triplet.push_back({r, c, v});
    }
    
    cout << "\nOriginal Triplet Representation:\n";
    for (int i = 0; i < triplet.size(); i++) {
        cout << triplet[i][0] << " " << triplet[i][1] << " " << triplet[i][2] << endl;
    }
    cout << "\nTranspose Triplet Representation:\n";
    for (int i = 0; i < triplet.size(); i++) {
        cout << triplet[i][1] << " " << triplet[i][0] << " " << triplet[i][2] << endl;
    }
}