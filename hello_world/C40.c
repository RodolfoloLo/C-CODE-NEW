#include<stdio.h>
void strcat(char* str1,char* str2){
    while(*str1!='\0'){
        str1++;
    }
    while(*str2!='\0'){
        *str1=*str2; //str2黏住str1黏住哈哈哈
        str1++;
        str2++;
    }
    *str1='\0';
}//字符串连接函数
void strdelete(char* str,char ch){
    char* p1=str;
    char* p2=str;
    while(*p2!='\0'){
        if(*p2!=ch){
            *p1=*p2;
            p1++;
        }
        p2++;
    }
    *p1='\0';
}//字符串删除函数
int main(){
    char str1[100],str2[100],ch;
    scanf("%s",str1);
    scanf("%s",str2);
    scanf(" %c",&ch);//现在缓冲区还有一个换行符，如果没有空格，scanf会读到这个换行符空格“ ”表示跳过所有空白字符
    strcat(str1,str2);
    printf("%s\n",str1);
    strdelete(str1,ch);
    printf("%s",str1);
    return 0;
}