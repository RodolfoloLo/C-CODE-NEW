#include<stdio.h>
#include<string.h>
void twotwochange(char str[],int len){
    for(int i=0;i<len-1;i+=2){
        char temp;
        temp=str[i+1];
        str[i+1]=str[i];
        str[i]=temp;
        if(str[i]=='\0'||str[i+1]=='\0'){
            break;
        }
    }
}
int main(){
    char str[81];
    fgets(str,sizeof(str),stdin);
    int k;
    scanf("%d",&k);
    char *p=str;
    while(*p!='\0'){
        if(*p>='A'&&*p<='Z'){
        *p='A'+(*p-'A'+k-1)%26;
        }
        p++;
    }
    int len=strlen(str);
    twotwochange(str,len);
    printf("%s",str);
    return 0;
}