#include<iostream>
#include<string>
using namespace std;

int main(){
    string s1;
    string s2;
    cout<<"Enter first string: ";
    getline(cin,s1);
     cout<<"Enter second string: ";
    getline(cin,s2);
    cout<<"Concatenated String is: "<<s1+s2;
}