#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int mystrlen(char*s){
    if(*s=='\0'){
        return 0;
    }else{
        return 1+mystrlen(s+1);
    }
}
int main(){
    char strlen;
    scanf("%s",&strlen);
    printf("%d",mystrlen(&strlen));
    return 0;
}