#include<stdio.h>
int digit(long n,int k){
    if(k<=0){
        return -1;
    }
    if(n<0){
        n=0-n;
    }
    for(int i=1;i<k;i++){
        n=n/10;
        if(n==0){
            return -1;
        }
    }
    return n%10;
}
int main(){
    long n;
    int k;
    scanf("%ld %d",&n,&k);
    printf("%d",digit(n,k));
    return 0;
}
//要善于考虑极端数据！！！