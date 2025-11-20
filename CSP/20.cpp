#include<bits/stdc++.h>
using namespace std;
struct grade{
    int chinese;
    int math;
    int english;
    int total;
    int number;
}analysis[305];
int n;
bool cmp(grade x,grade y){
    if(x.total!=y.total){
        return x.total>y.total;
    }else{
        if(x.chinese!=y.chinese){
            return x.chinese>y.chinese;
        }else{
            return x.number<y.number;
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>analysis[i].chinese>>analysis[i].math>>analysis[i].english;
        analysis[i].number=i;
        analysis[i].total=analysis[i].chinese+analysis[i].math+analysis[i].english;
    }
    sort(analysis+1,analysis+n+1,cmp);
    for(int i=1;i<=5;i++){
        cout<<analysis[i].number<<" "<<analysis[i].total<<endl;
    }
    return 0;
}