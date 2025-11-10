#include<stdio.h>
#define CHANGE 0
int main(){
    char str[100];
    int i=0;
    fgets(str,sizeof(str),stdin);
    #ifdef CHANGE
    while(str[i]){
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=str[i]+32;
        }else if(str[i]>='a'&&str[i]<='z'){
            str[i]=str[i]-32;
        }
        i++;
    }
    #endif

    printf("%s",str);
    return 0;
}