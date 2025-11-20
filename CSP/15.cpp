//搜索写累了，来写点模拟。。。
#include<bits/stdc++.h>
using namespace std;
void processgame(const string& records,int score_to_win){
    int w=0,l=0;
    for(char ch:records){
        if(ch=='E'){//便捷遍历字符串
            break;
        }
        if(ch=='W'){
            w++;
        }
        if(ch=='L'){
            l++;
        }
        if((w>=score_to_win||l>=score_to_win)&&abs(w-l)>=2){
            cout<<w<<":"<<l<<endl;
            w=0;
            l=0;
        }
    }
    cout<<w<<":"<<l<<endl;
}
int main(){
    string input,record;
    while(getline(cin,input)){
        for(char ch:input){
            if(ch!='E'){
                record+=ch;
            }else{
                record+=ch;
                break;
            }
        }
        if(!input.empty()&&input.find('E')!=string::npos){
            break;
        }
    }
    processgame(record,11);
    cout<<endl;
    processgame(record,21);
    return 0;
}