#include<stdio.h>
#include<math.h>
void conversion(char str[]){
    char *ptr=str;
    char new_str[100];
    int count=0;
    while(*ptr!='\0'&&*ptr!='\n'&&((*ptr>='a'&&*ptr<='f')||(*ptr>='A'&&*ptr<='F')||(*ptr>='0'&&*ptr<='9'))){
        new_str[count]=*ptr;
        count++;
        ptr++;
    }
    for(int i=0;i<count;i++){
        if(new_str[i]>='a'&&new_str[i]<='f'){
            new_str[i]=new_str[i]-'a'+10;
        }else if(new_str[i]>='A'&&new_str[i]<='F'){
            new_str[i]=new_str[i]-'A'+10;
        }else if(new_str[i]>='0'&&new_str[i]<='9'){
            new_str[i]=new_str[i]-'0';
        }
    }
    int result=0;
    for(int j=count-1;j>=0;j--){
        result+=new_str[j]*pow(16,count-j-1);
    }
    printf("%d",result);
}
int main(){
    char str[100];
    fgets(str,sizeof(str),stdin);
    conversion(str);
    return 0;
}