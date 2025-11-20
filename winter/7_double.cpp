#include<bits/stdc++.h>
using namespace std;
int main(){
    int x;
    cin>>x;
    int cnt=0;
    int y=2*x;
    while(y!=1){
        y/=2;
        cnt++;
    }
    cout<<(cnt)<<endl;
    return 0;
}