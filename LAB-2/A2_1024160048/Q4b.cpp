#include<iostream>
#include<string>
#include<algorithm>

// dhiren
// ram
using namespace std;
string reverse(string s){
    int size=s.size();
for(int i=0;i<=size/2;i++){
swap(s[i],s[size-i-1]);
}
return s;
}
int main(){
    string s1;
    cout<<"Enter first string: ";
    getline(cin,s1);
cout<<reverse(s1);
}