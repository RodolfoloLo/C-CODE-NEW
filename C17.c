#include<stdio.h>
//注意函数定义，调用时数组写法，以及如何写数组大小，
void inArray(int arr[],int size){
    for(int i=0;i<=size-1;i++){
        scanf("%d",&arr[i]);
    }
}
int findmaxindex(int arr[],int size){
    int maxindex=0;
    for(int j=1;j<=size-1;j++){
        if(arr[j]>arr[maxindex]){//注意比较逻辑！！！
            maxindex=j;
        }
    }
    return maxindex;//找的是最大值索引，不是那个最大值，思路要清晰
}
void selectSort(int arr[],int size){
    if(size>1){
        int maxindex=findmaxindex(arr,size);
        int temp=arr[maxindex];
        arr[maxindex]=arr[size-1];
        arr[size-1]=temp;
        selectSort(arr,size-1);//你需要做的是交换值，这样才能保存原始数据
    }
}
void outArray(int arr[],int size){
    for(int k=0;k<=size-1;k++){
        printf("%d ",arr[k]);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    int array[n];
    inArray(array,n);
    selectSort(array,n);
    outArray(array,n);
    return 0;
}