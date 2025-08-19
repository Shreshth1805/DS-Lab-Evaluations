#include <iostream>
using namespace std;
int main()
{
    int i;
    int arr[5] = {1};
    for (i = 0; i < 5; i++) 
        printf("%d",arr[i]);
    return 0;
}
//The output of the code above will be an error because we don't use printf in c++ instead we use cout to print.