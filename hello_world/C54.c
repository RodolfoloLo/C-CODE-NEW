#include<stdio.h>
void RemoveSame(int arr[],int n){
    int *ptr_find=NULL;
    int *ptr_index=NULL;
    int count=0;
    for(int i=0;i<n;i++){
        ptr_index=arr+i;
        for(int j=n-1;j>i;j--){
            ptr_find=arr+j;
            if(*ptr_index==*ptr_find&&*ptr_index!=0){
                *(arr+j)=0;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            count++;
        }
    }
    int first=1;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            if(!first){//思维，孩子
                printf(" ");
            }
            printf("%d",arr[i]);
            first=0;
        }
    }
    printf("\n");
    printf("%d",count);
}
int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    RemoveSame(arr,n);
    return 0;
}