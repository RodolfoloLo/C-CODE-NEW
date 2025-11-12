//这是广度优先搜索
#include<bits/stdc++.h>
#include<queue>
using namespace std;
const int maxn=405;
int n,m,x,y,a[maxn][maxn];//二维数组记录每个位置的最短步数！！！
int dx[8]={1,2,2,1,-1,-2,-2,-1},dy[8]={2,1,-1,-2,-2,-1,1,2};//方向数组
void init(){
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            a[i][j]=-1;
        }
    }
    a[x][y]=0;
}//把所有格子初始化为-1，（表达不可达或者未访问），起始位置（x，y）的步数设为0
void bfs(){
    queue<int>qx,qy;//两个队列分别存放x坐标和y坐标
    qx.push(x),qy.push(y);
    while(!qx.empty()){//队列不为空就继续
        int fx=qx.front(),fy=qy.front();//取出队首
        qx.pop(),qy.pop();//出队
        for(int i=0;i<8;++i){
            int tx=fx+dx[i],ty=fy+dy[i];
            if(tx<=0||ty<=0||tx>n||ty>m){
                continue;
            }
            if(a[tx][ty]==-1){
                a[tx][ty]=a[fx][fy]+1;
                qx.push(tx),qy.push(ty);
            }
        }
    }
}
int main(){
    cin>>n>>m>>x>>y;
    init();
    bfs();
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cout<<a[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}