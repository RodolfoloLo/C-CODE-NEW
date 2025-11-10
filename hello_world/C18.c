#include<stdio.h>
void move(int arr[],int n, int k){
    int temp[n];
    for(int i=0;i<=n-k-1;i++){
        temp[i]=arr[k+i];
    }
    for(int j=n-k;j<=n-1;j++){
        temp[j]=arr[j-n+k];
    }
    for(int w=0;w<=n-1;w++){
        arr[w]=temp[w];
    }
    for(int c=0;c<=n-1;c++){
        printf("%d ",arr[c]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    for(int c=0;c<=n-1;c++){
        scanf("%d",&array[c]);
    }
    int k;
    scanf("%d",&k);
    move(array,n,k);
    return 0;
}