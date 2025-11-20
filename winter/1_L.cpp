#include<bits/stdc++.h>
using namespace std;
int main(){
    int yuan,jiao;
    cin>>yuan>>jiao;
    int total=yuan*10+jiao;
    int cnt=0;
    int cost=0;
    while((cost+19)<=total){
        cost+=19;
        cnt++;
    }
    cout<<cnt;
    return 0;
}