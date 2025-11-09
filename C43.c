#include<stdio.h>
int main(){
    int n;
    scanf("%d",&n);
    int result[32];
    for(int i=0;i<=31;i++){
        result[i]=0;
    }
    unsigned int num=n;
    for(int i=31;i>=0;i--){
        result[i]=num&1;
        num=num>>1;
    }
    for(int i=0;i<=31;i++){
        if((i+1)%4==0){
            printf("%d ",result[i]);
        }else{
            printf("%d",result[i]);
        }
    }
    return 0;
}
//十进制数转换二进制数