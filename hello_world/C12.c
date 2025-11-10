#include<stdio.h>
#include<math.h>
int is_composite(int x){
    if(x<=3){
        return 0;
    }
    if((x&1)==0){
        return 1;
    }
    for(int i=3;i*i<=x;i+=2){
        if(x%i==0){
            return 1;
            break;
        }
    }
    return 0;
}
int judge(int y){
    while(is_composite(y)&&y>10){
        y=y/10;
        if(is_composite(y)&&y<10){
            return 1;
        }
    }
    return 0;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int p=(int)pow(10,n-1);p<(int)pow(10,n);p++){
        if(judge(p)){
            printf("%d ",p);
        }
    }
    return 0;
}