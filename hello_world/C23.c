#include<stdio.h>
//冒泡排序
void bubble_sort(int arr[],int n){
    int *p=arr;
    for(int i=0;i<=n-2;i++){
        for(int j=0;j<=n-i-1;j++){
            if(*(p+j)>*(p+j+1)){
                int temp=*(p+j);
                *(p+j)=*(p+j+1);
                *(p+j+1)=temp;//指针交换值的操作！！！
            }
            p=arr;
        }
    }
}
int main(){
    int arr[10];
    for(int i=0;i<=9;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr,10);
    for(int i=0;i<=9;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}