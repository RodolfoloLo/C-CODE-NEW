#include<bits/stdc++.h>
using namespace std;
int main(){
    double S;
    cin>>S;
    vector<double> s;//vector为空时不能用下标!
    s.push_back(2.0);
    double l=0;
    int i;
    for(i=0;;i++){
        l+=s[i];
        if(l>=S){
            break;
        }
         s.push_back(s[i]*0.98);//注意考虑操作顺序！！！
    }
    cout<<++i<<endl;
    return 0;
}