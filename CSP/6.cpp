/*题目描述
只要一个由 N×M 个小方块组成的旗帜符合如下规则，就是合法的图案。

从最上方若干行（至少一行）的格子全部是白色的；
接下来若干行（至少一行）的格子全部是蓝色的；
剩下的行（至少一行）全部是红色的；
现有一个棋盘状的布，分成了 N 行 M 列的格子，每个格子是白色蓝色红色之一，小 a 希望把这个布改成合法图案，方法是在一些格子上涂颜料，盖住之前的颜色。

小 A 很懒，希望涂最少的格子，使这块布成为一个合法的图案。

输入格式
第一行是两个整数 N,M。

接下来 N 行是一个矩阵，矩阵的每一个小方块是 W（白），B（蓝），R（红）中的一个。

输出格式
一个整数，表示至少需要涂多少块。
对于100%的数据，N,M<=50 */

/*
思路，简单粗暴，练习一下暴力枚举吧
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,M;
    cin>>N>>M;
    int result=0;
    int min_result=N*M;
    char board[N][M];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
        }
    }
    for(int i0=0;i0<N-2;i0++){//确定白色区域：0~i0行
        for(int i1=i0+1;i1<N-1;i1++){//确定蓝色区域：i0+1~i1行，同时，红色区域：i1+1~N-1行也就确定了
            int result=0;//重置计数器
            //白色，蓝色，红色区域分开计数！

            //白色区域涂色
            for(int i=0;i<=i0;i++){
                for(int j=0;j<M;j++){
                    if(board[i][j]!='W'){
                        result++;
                    }
                }
            }
            //蓝色区域涂色
            for(int i=i0+1;i<=i1;i++){
                for(int j=0;j<M;j++){
                    if(board[i][j]!='B'){
                        result++;
                    }
                }
            }
            //红色区域涂色
            for(int i=i1+1;i<=N-1;i++){
                for(int j=0;j<M;j++){
                    if(board[i][j]!='R'){
                        result++;
                    }
                }
            }
            if(result<min_result){
            min_result=result;
            }
        }
    }
    cout<<min_result<<endl;
    return 0;
}