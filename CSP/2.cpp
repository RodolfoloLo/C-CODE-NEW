/*题目描述
有一个 n×m 方格的棋盘，求其方格包含多少正方形、长方形（不包含正方形）。

输入格式
一行，两个正整数 n,m（n≤5000,m≤5000）。

输出格式
一行，两个正整数，分别表示方格包含多少正方形、长方形（不包含正方形）。*/
#include<iostream>
using namespace std;
long long n,m,rec,sqr;
int main() {
    cin>>n>>m;
    for(int i=0; i<n; i++)//循环，从n-0到n-(n-1)
        for(int j=0; j<m; j++) {//循环，从m-0到m-(m-1)
            if(i==j) sqr+=(n-i)*(m-j);//如果i==j，说明是正方形
            else rec+=(n-i)*(m-j);//如果不等说明是矩形
        }
    cout<<sqr<<" "<<rec<<endl;//输出
    return 0;
}
//暴力枚举第一课