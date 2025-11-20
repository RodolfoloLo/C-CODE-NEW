#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>number(3);
    for(int i=0;i<3;i++){
        cin>>number[i];
    }
    sort(number.begin(),number.end());
    for(int i=0;i<3;i++){
        cout<<number[i]<<" ";
    }
    return 0;
}