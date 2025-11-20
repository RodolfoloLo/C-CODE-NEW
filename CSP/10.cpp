//再写一遍马的遍历吧~bfs经典例题永不过时~
#include<bits/stdc++.h>
using namespace std;
const int maxn=405;
const int maxm=405;
//"+5"是一个好习惯！
int board[maxn][maxm];
int dx[8]={1,1,-1,-1,2,2,-2,-2};
int dy[8]={2,-2,2,-2,1,-1,1,-1};
int n,m,X,Y;
struct pos{
    int x;
    int y;
};
void init_board(){
    for(int i=0;i<maxn;i++){
        for(int j=0;j<maxm;j++){
            board[i][j]=-1;//标答不可达或者未访问
        }
    }
    board[X][Y]=0;//起始位置最少要走0步
}
void bfs_horse(){//有全局变量就不用传参了~
    queue<pos> q;
    q.push({X,Y});
    while(!q.empty()){
        pos current=q.front();
        q.pop();

        int current_x=current.x;
        int current_y=current.y;
        for(int i=0;i<8;i++){
            int new_x=current_x+dx[i];
            int new_y=current_y+dy[i];
            if(new_x<=0||new_y<=0||new_x>n||new_y>m){
                continue;
            }
            if(board[new_x][new_y]==-1){
                board[new_x][new_y]=board[current_x][current_y]+1;
                q.push({new_x,new_y});
            }
        }
    }
}
int main(){
    cin>>n>>m>>X>>Y;
    init_board();
    bfs_horse();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    return 0;
}
//难道是天才？？？没有deepseek一遍过？！