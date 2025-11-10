#include<stdio.h>
//指针！！！
void mysteryfunction(int *p1,int *p2){
    p1=p2;
    *p1=100;
    *p2=200;
}

int main(){
    int a=10,b=20;
    int *ptr1=&a;
    int *ptr2=&b;

    printf("(1)��ʼֵ��a=%d,b=%d\n",a,b);

    mysteryfunction(ptr1,ptr2);

    printf("(2)���ú�����:a=%d,b=%d\n",a,b);
    printf("(3)*ptr1=%d,*ptr2=%d\n",*ptr1,*ptr2);

    return 0;
}