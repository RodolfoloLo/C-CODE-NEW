#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>result(4,0);
    int x;
    cin>>x;
    if(x%2==0&&(x>4&&x<=12)){
        result[0]=1;
    }
    if(x%2==0||(x>4&&x<=12)){
        result[1]=1;
    }
    if((x%2==0&&(x<=4||x>12))||(x%2!=0&&(x>4&&x<=12))){
        result[2]=1;
    }
    if(x%2!=0&&(x<=4||x>12)){
        result[3]=1;
    }
    for(auto it=result.begin();it!=result.end();it++){
        cout<<*it<<" ";
    }
    return 0;
}