//再练最后一道模拟。。。
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    pair<int,string>characters[n];
    pair<int,int>commands[m];
    for(int i=0;i<n;i++){
        cin>>characters[i].first>>characters[i].second;
    }
    for(int i=0;i<m;i++){
        cin>>commands[i].first>>commands[i].second;
    }
    int start=characters[0].first;
    int pos=0;
    for(int i=0;i<m;i++){
        if(start==commands[i].first){
            while(pos-commands[i].second<0){
                pos+=n;
            }
            pos=pos-commands[i].second;
            start=characters[pos].first;
        }else{
            while(pos+commands[i].second>=n){
                pos-=n;
            }
            pos=pos+commands[i].second;
            start=characters[pos].first;
        }
    }
    cout<<characters[pos].second<<endl;
    return 0;
}