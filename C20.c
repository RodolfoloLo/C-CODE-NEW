#include<stdio.h>
void strnCpy(char t[],char s[],int n){
    char temp[n];
    for(int i=0;i<=n-1;i++){
        temp[i]=s[i];
    }
    temp[n]='\0';//良好的编程习惯
    for(int j=0;j<=n;j++){
        t[j]=temp[j];
    }
    for(int k=0;k<=n-1;k++){
        if(t[k]!='\0'){
            printf("%c",t[k]);
        }
    }
}
int main(){
    char s[100];
    for(int c=0;c<=99;c++){
        s[c]=getchar();
        if(s[c]=='\n'){
            break;
        }
    }
    int n;
    scanf("%d",&n);
    char t[n];
    strnCpy(t,s,n);
    return 0;
}