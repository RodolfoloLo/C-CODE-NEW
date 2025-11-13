/*
任务描述
本关任务：编程实现
（1）用一个单向链表接收一个长字符串，且每个节点接收一个字符，遍历输出链表中的所有字符，并将字符串无冗余地存放到一个动态存储分配的的字符数组中，
并且输出该字符串。（本题暂不考虑空字符串情况）(结尾以回车结束)
（2）再输入一个字符，如果该字符已在链表中，则删除该结点，否则在输入字符和结点的数据域字符差值最小的结点后面插入包含该字符的结点，输出最后的字符串。

要求：采用模块化设计方法，将创建链表、遍历链表、删除结点、插入结点等功能用函数实现。

测试说明
平台会对你编写的代码进行测试，若是与预期输出相同，则算通关。

测试输入：
qwertyuiopasdfghjkl
i
预期输出：
q w e r t y u i o p a s d f g h j k l
qwertyuiopasdfghjkl
qwertyuopasdfghjkl

测试输入：
qwertyuiopasdfghjkl
q
预期输出：
q w e r t y u i o p a s d f g h j k l
qwertyuiopasdfghjkl
wertyuiopasdfghjkl

测试输入：
qwer1234?@%
5
预期输出：
q w e r 1 2 3 4 ? @ %
qwer1234?@%
qwer12345?@%

开始你的任务吧，祝你成功！
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct one_char{
    char ch;
    struct one_char *next;
};
struct one_char *head=NULL;
void create_list(){
    struct one_char *p,*tail;
    tail=NULL;
    char c;
    while(1){
        p=(struct one_char*)malloc(sizeof(struct one_char));
        scanf("%c",&c);
        if(c=='\n'){
            break;
        }
        p->ch=c;
        if(head==NULL){
            head=p;
            tail=p;
            tail->next=NULL;
        }else{
            tail->next=p;
            tail=p;
            tail->next=NULL;
        }
    }
}
void printf_original(){
    struct one_char *p=head;
    while(p!=NULL){
        printf("%c",p->ch);
        if(p->next!=NULL){
            printf(" ");
        }
        p=p->next;
    }
    printf("\n");
}
void list_to_array_and_print(){
    int len=0;
    struct one_char *p=head;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    char *array=(char*)malloc((len+1)*sizeof(char));
    p=head;
    for(int i=0;i<len;i++){
        array[i]=p->ch;
        p=p->next;
    }
    array[len]='\0';
    printf("%s\n",array);
    free(array);
}
int find(char target){
    struct one_char *p=head;
    while(p!=NULL){
        if(p->ch==target){
            return 1;
        }
        p=p->next;
    }
    return 0;
}
void delete_target(char target){
    struct one_char *p=head,*prev=NULL,*temp;
    while(p!=NULL){
        if((p->ch)==target){
            if(prev==NULL){
                head=p->next;
                temp=p;
                p=p->next;
                free(temp);
            }else{
                prev->next=p->next;
                temp=p;
                p=p->next;
                free(temp);
            }
        }else{
            prev=p;
            p=p->next;
        }
    }
}
void insert_at_mindiff(char target){
     // 先找到最小差值
    int min_diff = 1000; // 设一个很大的初始值
    struct one_char *p = head;
    
    while(p != NULL){
        int diff = abs(target - p->ch);
        if(diff < min_diff){
            min_diff = diff;
        }
        p = p->next;
    }
    
    // 在所有等于最小差值的节点后插入
    p = head;
    while(p != NULL){
        int diff = abs(target - p->ch);
        if(diff == min_diff){
            struct one_char *new_node = (struct one_char*)malloc(sizeof(struct one_char));
            new_node->ch = target;
            new_node->next = p->next;
            p->next = new_node;
            p = new_node; // 跳过新插入的节点，避免无限循环
        }
        p = p->next;
    }
}
void print_final(){
    struct one_char *p=head;
    while(p!=NULL){
        printf("%c",p->ch);
        p=p->next;
    }
    printf("\n");
}
int main(){
    create_list();
    printf_original();
    list_to_array_and_print();
    char target;
    scanf("%c",&target);
    if(find(target)){
        delete_target(target);
    }else{
        insert_at_mindiff(target);
    }
    print_final();
    return 0;
}