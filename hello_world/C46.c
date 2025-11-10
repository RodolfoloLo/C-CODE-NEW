#include<stdio.h>
#include<string.h>
void str_n_ins(char *t,char *s,int n){
    char *s_ptr=s;
    char *t_ptr=t;//两个字符串各配置一个指针
    char buffer[7723];
    char *buffer_ptr=buffer;//缓冲区
    int i=0;
    while(i<n&&*s_ptr!='\0'){
        *buffer_ptr=*s_ptr;
        buffer_ptr++;
        s_ptr++;
        i++;
    }
    while(*t_ptr!='\0'){
        *buffer_ptr=*t_ptr;
        buffer_ptr++;
        t_ptr++;
    }
    while(*s_ptr!='\0'){
        *buffer_ptr=*s_ptr;
        buffer_ptr++;
        s_ptr++;
    }
    *buffer_ptr='\0';
    strcpy(s,buffer);
}
int main(){
    char s_string[77];
    char t_string[77];
    fgets(s_string,77,stdin);
    fgets(t_string,77,stdin);
    s_string[strcspn(s_string,"\n")]='\0';
    t_string[strcspn(t_string,"\n")]='\0';
    int n;
    scanf("%d",&n);
    str_n_ins(t_string,s_string,n);
    printf("%s\n",s_string);
    return 0;
}