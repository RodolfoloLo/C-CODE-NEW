#include<iostream>
#include<string>
using namespace std;
int main(){
    string s="hello.cpp!";
    cout<<s.length()<<endl;
    cout<<s.size()<<endl;
    cout<<s[0]<<endl;
    cout<<s[s.length()-1]<<endl;
    string emptystr="";
    cout<<s.empty()<<endl;
    cout<<emptystr.empty()<<endl;
    return 0;
}