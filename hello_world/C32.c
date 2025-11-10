#include<stdio.h>
#include<string.h>
#define N 4
struct web{
    char shortname[20];
    char fullname[50];
    char url[100];
};
void sort(struct web webs[],int n){
    struct web temp;//设置一个临时变量用于交换！！！
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(strcmp(webs[j].shortname,webs[j+1].shortname)>0){//字符串比较函数，首先比较首字母，相同再比较第二个字母，可以直接看首字母返回大于0小于0
                temp=webs[j];
                webs[j]=webs[j+1];
                webs[j+1]=temp;
            }
        }
    }
}
int main(){
    struct web webs[N];
    for(int i=0;i<N;i++){
        scanf("%s %s %s",webs[i].shortname,webs[i].fullname,webs[i].url);
    }
    char shortname_input[20];
    scanf("%s",shortname_input);
    sort(webs,N);
    for(int i=0;i<N;i++){
        printf("%s %s %s\n",webs[i].shortname,webs[i].fullname,webs[i].url);
    }
    int flag=0;
    for(int i=0;i<N;i++){
        if(strcmp(webs[i].shortname,shortname_input)==0){
            printf("%s\n",webs[i].url);
            flag=1;
            break;
        }
    }
    if(flag==0){
        printf("未找到搜寻的地址\n");
    }
    return 0;
}