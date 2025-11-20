//bfs,接着练！
#include<bits/stdc++.h>
using namespace std;
const int MAX=305;
const int INF=1e9;
int M;
vector<vector<int>>board(MAX,vector<int>(MAX));
vector<int>dangerous_x(50005);
vector<int>dangerous_y(50005);
vector<int>dangerous_t(50005);
//每个危险点的x坐标，y坐标，t都标记好
int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,1,-1};

struct state{
    int x,y,t;
};

int bfs_meteor(){
    //初始化board，所有位置初始为INF（安全）
    for(int i=0;i<MAX;i++){
        for(int j=0;j<MAX;j++){
            board[i][j]=INF;
        }
    }
    //标记危险区域
    for(int i=0;i<M;i++){
        int x=dangerous_x[i];int y=dangerous_y[i];int t=dangerous_t[i];
        for(int j=0;j<5;j++){
            int nx=x+dx[j];
            int ny=y+dy[j];
            if(nx>=0&&nx<MAX&&ny>=0&&ny<MAX){
                board[nx][ny]=min(board[nx][ny],t);
            }
        }
    }
    //~每个board的值是board中每个点被砸中的时间
    if(board[0][0]==0){
        return -1;
    }
    //0时刻，点0,0就不幸的被砸中（考虑极端情况）！

    queue<state> q;//bfs和queue深度绑定！
    vector<vector<bool>>visited(MAX,vector<bool>(MAX,false));

    q.push({0,0,0});
    visited[0][0]=true;

    while(!q.empty()){
        state current=q.front();
        q.pop();
        //队列头：一旦访问完了，就踢了
        int x=current.x;int y=current.y;int t=current.t;
        if(board[x][y]==INF){
            return t;
        }
        //关于时间的巧妙处理~board[x][y]==INF说明这个点没有被砸中！
        for(int i=1;i<5;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            int nt=t+1;
            if(nx>=0&&nx<MAX&&ny>=0&&ny<MAX&&!visited[nx][ny]){
                if(nt<board[nx][ny]){
                    visited[nx][ny]=true;
                    q.push({nx,ny,nt});
                }
            }
        }
    }
    return -1;
}
int main(){
    cin>>M;
    for(int i=0;i<M;i++){
        cin>>dangerous_x[i]>>dangerous_y[i]>>dangerous_t[i];
    }
    int result=bfs_meteor();
    cout<<result<<endl;
    return 0;
}