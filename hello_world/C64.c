/*任务描述
实验教材P207 程序设计 第（4）题
本关任务：
回文字符串是正读和反读都相同的字符串，例如“abba”和“abcba”是回文字符串。设计程序判断输入的任意长度的字符串是否为回文字符串。
提示：由于要求字符串长度任意，所以用单链表存储字符串，即判断一个单链表是否为回文链表。

编程要求
根据题目要求，在右侧编辑器中两个函数的算法设计。

void createLinkList(C_NODE **headp, char s[]) 根据字符串s构造单链表，得到一个以单链表表示的字符串，单链表结点定义见右侧编辑器。
void judgePalindrome(C_NODE *head) 判断以head为头指针的单链表表示的字符串是否为回文，是则显示true，否则显示false。
测试程序定义了如下结点类型
typedef struct c_node{
    char data;  struct c_node *next;
} C_NODE;*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct c_node{
    char data;
    struct c_node *next;
}C_NODE;
void createLinkList(C_NODE **head,char s[]){
    C_NODE *p,*tail=NULL;
    *head=NULL;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        p=(C_NODE*)malloc(sizeof(C_NODE));
        p->data=s[i];
        p->next=NULL;
        if(*head==NULL){
            *head=p;
            tail=p;
        }else{
            tail->next=p;
            tail=p;
        }
        p->next=NULL;
    }
}
void judgePalindrome(C_NODE *head){
    if(head==NULL){
        printf("true\n");
        return;
    }
    C_NODE *slow=head,*fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;//妙啊
    }
    C_NODE *prev=NULL,*cur=slow,*next;
    //翻转后半部分链表
    while(cur!=NULL){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    //比较前后两部分
    C_NODE *first=head,*second=prev;
    int isPalindrome=1;
    while(second!=NULL){
        if(first->data!=second->data){
            isPalindrome=0;
            break;
        }
        first=first->next;
        second=second->next;
    }
    if(isPalindrome){
        printf("true");
    }else{
        printf("false");
    }
}
int main(){
    char s[7777];
    fgets(s,7777,stdin);
    s[strcspn(s,"\n")]='\0';
    C_NODE *head=NULL;
    createLinkList(&head,s);
    judgePalindrome(head);
    C_NODE *p=head;
    while(p!=NULL){
        C_NODE *temp=p;
        p=p->next;
        free(temp);
    }
    return 0;
}