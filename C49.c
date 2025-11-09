//迷宫问题！！！
#include<stdio.h>
int X,Y;
int maze[77][77];
int visited[77][77];
int path[77][77];
int solution_count=0;
//方向数组！
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
void printf_solution(){
    solution_count++;
    printf("%d\n",solution_count);
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            printf("%d ",path[i][j]);
        }
        printf("\n");
    }
}
void dfs(int x,int y){
    if(x==X-1&&y==Y-1){
        path[x][y]=1;//将终点位置标记为“在路径中”
        printf_solution();
        path[x][y]=0;//取消终点的路径标记
        return;//结束这条路径的探索
    }
    //
    visited[x][y]=1;
    path[x][y]=1;
    for(int d=0;d<4;d++){
        int new_x=x+dx[d];
        int new_y=y+dy[d];
        if(new_x>=0&&new_x<X&&new_y>=0&&new_y<Y&&maze[new_x][new_y]==1&&visited[new_x][new_y]==0){
            dfs(new_x,new_y);
        }
    }
    visited[x][y]=0;
    path[x][y]=0;
}
int main(){
    scanf("%d %d",&X,&Y);
    for(int i=0;i<X;i++){
        for(int j=0;j<Y;j++){
            scanf("%d",&maze[i][j]);
            visited[i][j]=0;
            path[i][j]=0;
        }
    }
    if(maze[0][0]==1){
        dfs(0,0);
    }
    return 0;
}