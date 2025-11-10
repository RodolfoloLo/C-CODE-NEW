#include<stdio.h>
int isPrime(int x){
    if(x==1||x==2){
        return 0;
    }
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return 0;
            break;
        }
    }
    return 1;
}
int main(){
    int m;
    scanf("%d",&m);
    for(int n=1;n<=m-2;n++){
        if(isPrime(n)){
            if(isPrime(n+2)){
                printf("(%d,%d)",n,n+2);
            }
        }
    }
    return 0;
}