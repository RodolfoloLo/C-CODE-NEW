#include<stdio.h>
//辗转相除法 用较大数除以较小数得到余数 然后用除数除以余数 重复 余数为0时，除数即最大公约数
int gcd(int x,int y){
    printf("%d %d\n",x,y);
    if(y==0){
        printf("%d",x);
        return x;
    }
    int z=x%y;
    return gcd(y,z);
}
int main(){
    int x,y;
    scanf("%d %d",&x,&y);
    gcd(x,y);
    return 0;
}