#include <stdio.h>
#include <stdlib.h>
struct s_list{
    int data;
    struct s_list *next;
};
struct s_list* create_list(){//头插法
    struct s_list *head,*p;
    head=NULL;
    int x;
    scanf("%d",&x);
    while(x){
        p=(struct s_list*)malloc(sizeof(struct s_list));
        p->data=x;
        p->next=head;
        head=p;
        scanf("%d",&x);
    }
    return head;
}
void print_list(struct s_list *head){
    struct s_list *temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
}
int main(){
    print_list(create_list());
    return 0;
}