//再熟悉一下next_premutation
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector <int> vec(n);
    for(int i=0;i<n;i++){
        vec[i]=i+1;
    }
    do{
        for(int i=0;i<n;i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    }while(next_permutation(vec.begin(),vec.end()));
    return 0;
}