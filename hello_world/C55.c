/*任务描述
实验教材P206 2.源程序修改替换 第（1）题
    给定一批整数，以 0 为结束标志且不作为结点，将其建成一个先进先出的链表，先进先出链表的头指针始终指向最先创建的结点（链头），先建结点指向后建结点，后建结点始终是尾结点。

本关任务：
   对源程序进行修改、调试，使之能够正确完成指定任务。本题在书中源程序的基础上做以下改动：通过键盘输入给数组s的元素赋值，以0结束输入，且0作为数组的最后一个元素。
*/
#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;
};
void create_list(struct s_list **headp,int *p){//尾插法
    struct s_list *loc_head=NULL,*tail;
    if(p[0]==0);
    else {
        loc_head=(struct s_list *)malloc(sizeof(struct s_list));
        loc_head->data=*p++;
        tail=loc_head;
        while (*p)
        {
            tail->next=(struct s_list *)malloc(sizeof(struct s_list));
            tail=tail->next;
            tail->data=*p++;
        }
        tail->next=NULL;
        
    }
    *headp=loc_head;
}

int main(void){
    struct s_list *head=NULL,*p;
    int s[100];
    int len=0;
    for(int i=0;i<100;i++){
        scanf("%d",&s[i]);
        if(s[i]==0){
            break;
        }
        len++;
    }
    int *new_s=(int*)malloc(len*sizeof(int));
    for(int i=0;i<len;i++){
        new_s[i]=s[i];
    }
    new_s[len]=0;
    create_list(&head,new_s);
    p=head;
    while (p){
        printf("%d\t",p->data);
        p=p->next;
    }
    printf("\n");
    return 0;  
}

