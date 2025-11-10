#include<stdio.h>
#include<math.h>
int isPrime(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            return 0;
            break;
        }
    }
    return 1;
}
int main(){
    long long int m;
    scanf("%d",&m);
    int mason[10000];
    for(int i=1;i<=10000;i++){
        mason[i-1]=pow(2,i)-1;
    }
    for(int j=0;mason[j]<=m;j++){
        if(isPrime(j+1)){
            if(isPrime(mason[j])==1&&mason[j]!=1){
                printf("M(%d)=%d\n",j+1,mason[j]);
            }
        }
    }
    return 0;
}