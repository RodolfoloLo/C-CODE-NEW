//排序，从现在开始学
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>vote(m);
    for(int i=0;i<m;i++){
        cin>>vote[i];
    }
    sort(vote.begin(),vote.end());
    for(int run:vote){
        cout<<run<<" ";
    }
    //sort和next_premutation请分清楚！
    return 0;
}