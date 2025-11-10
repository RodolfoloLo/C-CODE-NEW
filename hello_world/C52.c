#include<stdio.h>
#include<stdlib.h>
void task(char *cmd){
    char *ptr=cmd;
    while(*ptr!='\0'&&*ptr!='\n'){
        printf("task %c is called\n",*ptr);
        ptr++;
    }
}
int main(){
    char *cmd=(char*)malloc(100*sizeof(char));//你用了指针定义就要牢记初始化或者分配动态内存！
    fgets(cmd,100,stdin);
    task(cmd);
    free(cmd);
    return 0;
}