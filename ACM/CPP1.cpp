#include<bits/stdc++.h>
using namespace std;
const int maxn=25;
int a[maxn],n,k,ans;
bool is_prime(int x){//判断是否是素数！
    if(x==1)
    return false;
    if(x==2)
    return true;
    if(x%2==0)
    return false;
    for(int i=3;i*i<=x;i+=2){//简单优化一下，i为偶数时不必考虑
        if(x%i==0)
        return false;
    }
    return true;
}
void search(int count,int sum,int u){//count表示目前选了几个数，u表示目前枚举到了第几个数，
    if(n-u+1<k-count||count>k)//剩下的数不够了:n-u+1是从当前位置u到数组末尾还有多少个元素
    return;
    if(u>n){
        if(count!=k)
        return;
        if(is_prime(sum)){
            ans++;
        }
        return;//
    }
    search(count,sum,u+1);//不选择第u个数
    search(count+1,sum+a[u],u+1);//了第u个数，第u个数已经处理完了，要处理第u+1个数
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;++i)
    cin>>a[i];
    search(0,0,1);
    cout<<ans;
    return 0;
}
/*思考点：1如何在n个数里面选择k个数
2弄清楚递归在干什么！！！
  一些笔记   搜索、dfs深度优先递归一条路走到头、bfs广度优先队列同时走很多条路（就像有很多个分身一起在走迷宫哈哈哈）、减枝、记忆化、
队列/先进先出 queue队列 队尾入队 队首出队 取队首元素 队列是否为空
递归暴力枚举
正确选择d和b bfs的核心思想是按层拓展 层次性 最优性 最短路径 最少步骤 缺乏回溯 回溯dfs核心
dfs+记忆化搜索思想 大大的优化 缩短计算时间
递归是个啥！
减枝 顾名思义 记忆化搜索难以记录状态 省去
记忆化搜索 动态规划 相通
斐波那契数列 选数 八皇后 马 吃奶酪 魔法*/