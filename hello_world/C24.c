#include<stdio.h>
void reverseOrder(int a[],int n){
    int *start=&a[0];
    int *end=&a[n-1];
    for(;start<end;start++,end--){
        int temp=*start;
        *start=*end;
        *end=temp;
    }
    for(int i=0;i<=n-1;i++){
        printf("%d ",a[i]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<=n-1;i++){
        scanf("%d",&a[i]);
    }
    reverseOrder(a,n);
    return 0;
}