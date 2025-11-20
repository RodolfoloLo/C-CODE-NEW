#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<char>>board(n,vector<char>(m));
    int dx[8]={1,1,1,-1,-1,-1,0,0};
    int dy[8]={0,1,-1,0,1,-1,1,-1};
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>board[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(board[i][j]=='?'){
                int way=0;
                for(int k=0;k<8;k++){
                    int new_x=i+dx[k];
                    int new_y=j+dy[k];
                    if(new_x>=0&&new_x<n&&new_y>=0&&new_y<m){
                        if(board[new_x][new_y]=='*'){
                            way++;
                        }
                    }
                }
                cout<<way;
                way=0;
            }else{
                cout<<'*';
            }
        }
        cout<<endl;
    }
    return 0;
}