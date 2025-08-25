#include<iostream>
#include<string>
using namespace std;
string voweldelete(string s,int size){
    for(int i=0;i<size;i++){
        if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
          s.erase(i,1);
          i--;
        }
    }
    return s;
}
int main(){
    string s1;
    cout<<"Enter first string: ";
    getline(cin,s1);
    int size=s1.size();
cout<<voweldelete(s1,size);
}