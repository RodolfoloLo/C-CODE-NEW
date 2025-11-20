#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int leauingz_time;
    int you_time;
    leauingz_time=n*3+11;
    you_time=n*5;
    if(you_time<leauingz_time){
        cout<<"Local"<<endl;
    }else{
        cout<<"Luogu"<<endl;
    }
    return 0;
}