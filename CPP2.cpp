#include<bits/stdc++.h>
using namespace std;
int n,ans,a[14];//a[x]=y表示第x行的第y个格子有棋子
bool is[14];
bool check(int len){
    for(int i=1;i<len;++i){
        for(int j=i+1;j<=len;++j){
            if(abs(a[i]-a[j])==j-i){
            return false;
            }
        }
    }
    return true;
}//检查对角线是否符合条件
void dfs(int u){//深度优化搜索 回溯算法的核心！！！//表示搜索到了第u行
    if(u>n){
        if(check(n)){
            ans++;
            if(ans<=3){
                for(int i=1;i<=n;++i)//循环输出
                cout<<a[i]<<' ';
            cout<<endl;
            }
        }
        return;
    }
    for(int i=1;i<=n;++i){
        if(!is[i]){//保证数字i没有被选过，即一列只能有一个棋子
            is[i]=true;
            a[u]=i;
            if(check(u)){
                dfs(u+1);
            }
            is[i]=false;//记住回溯状态！很重要
        }//把花括号当作地盘的边界 好好看看代码
    }
}
int main(){
    cin>>n;
    dfs(1);
    cout<<ans;
    return 0;
}
//搜索，就是对状态空间进行枚举，通过穷尽所有的可能来找到最优解，或者统计合法解的个数
//优化方式，减小状态空间，更改搜索顺序，剪枝 