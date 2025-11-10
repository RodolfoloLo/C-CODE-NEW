#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int fangzhen[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            fangzhen[i][j]=0;
        }
    }
    int number=1;
    int x=0;
    int y=0;
    fangzhen[x][y]=number;
    while(number<(n*n)){//输入不输出一定要检查有没有陷入无限循环！！！
        if(y<=n-2&&fangzhen[x][y+1]==0){
            number++;
            fangzhen[x][y+1]=number;
            y++;
            continue;
        }
        if(x<=n-2&&fangzhen[x+1][y]==0){
            number++;
            fangzhen[x+1][y]=number;
            x++;
            continue;
        }
        if(y>=1&&fangzhen[x][y-1]==0){
            number++;
            fangzhen[x][y-1]=number;
            y--;
            continue;
        }
        if(x>=1&&fangzhen[x-1][y]==0){
            number++;
            fangzhen[x-1][y]=number;
            x--;
            continue;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(j<n-1)
            printf("%d ",fangzhen[i][j]);
            if(j==n-1)
            printf("%d",fangzhen[i][j]);
        }
        printf("\n");
    }
    return 0;
}