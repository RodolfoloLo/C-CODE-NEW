#include<stdio.h>
int is_Prime(int n){
    if(n<=1){
        return 0;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return 0;
        }
    }
    return 1;
}
void goldbach(int n){
    if(n%2==0&&n>=4){
        for(int i=2;i<=n/2;i++){
            if(is_Prime(i)&&is_Prime(n-i)){
                printf("%d=%d+%d\n",n,i,n-i);
                break;
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    goldbach(n);
    return 0;
}