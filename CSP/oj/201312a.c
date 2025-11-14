//出现最多次数的数
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
    scanf("%d",&n);
    int *arr=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int record[n];
    for(int i=0;i<n;i++){
        record[i]=0;
    }
    for(int i=0;i<n;i++){
        for(int j=n-1;j>i;j--){
            if(arr[i]==arr[j]){
                record[i]++;
            }
        }
    }
    int max=record[0];
    int max_index=0;
    for(int k=1;k<n;k++){
        if(record[k]>max){
            max=record[k];
            max_index=k;
        }
    }
    printf("%d",arr[max_index]);
    free(arr);
    return 0;
}