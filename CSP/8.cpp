//P2392,练习一下搜索吧
#include<bits/stdc++.h>
using namespace std;
int s[4];//记录每门科目题目数量
int t[4][25];//记录每道题目需要的时间&“+5”的好习惯
int dfs(int subject,int index,int left,int right){
    if(index==s[subject]){//所有题目分配完毕
        return max(left,right);
    }
    //当前题目分配给左脑
    int ans1=dfs(subject,index+1,left+t[subject][index],right);
    //当前题目分配给右脑
    int ans2=dfs(subject,index+1,left,right+t[subject][index]);
    return min(ans1,ans2);
}//"为什么本题不需要回溯？"：参数left，right，是值传递，每次递归调用都会
//创建新的副本，递归返回后，当前层的left，right保持不变，相当于自动回溯~
int main(){
    for(int i=0;i<4;i++){
        cin>>s[i];
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<s[i];j++){
            cin>>t[i][j];
        }
    }
    int shortest_time=0;
    for(int i=0;i<4;i++){
        shortest_time+=dfs(i,0,0,0);
    }
    cout<<shortest_time<<endl;
    return 0;
}