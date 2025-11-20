#include<bits/stdc++.h>
using namespace std;
int N,M,T;
int solution=0;
vector<vector<int>>board;
vector<vector<bool>>visited;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
void dfs(int current_x,int current_y,int target_x,int target_y){
    if(current_x==target_x&&current_y==target_y){
        solution++;
        return;
    }
    for(int i=0;i<4;i++){
        int new_x=current_x+dx[i];
        int new_y=current_y+dy[i];
        if(new_x>=1&&new_x<=N&&new_y>=1&&new_y<=M&&visited[new_x][new_y]==0&&board[new_x][new_y]==1){
            visited[new_x][new_y]=true;
            dfs(new_x,new_y,target_x,target_y);
            visited[new_x][new_y]=false;
        }
    }
}
int main(){
    cin>>N>>M>>T;
    int start_x,start_y,target_x,target_y;
    cin>>start_x>>start_y>>target_x>>target_y;
    board.resize(N+1,vector<int>(M+1,1));
    visited.resize(N+1,vector<bool>(M+1,false));
    int o_x,o_y;
    for(int i=1;i<=T;i++){
        cin>>o_x>>o_y;
        board[o_x][o_y]=0;
    }
    visited[start_x][start_y]=true;
    dfs(start_x,start_y,target_x,target_y);
    cout<<solution<<endl;
    return 0;
}