#include<stdio.h>
#include<ctype.h>
#include<string.h>
int target_count(char target[11],char text[1000001]){
    char *p1=target;
    char *p2=text;
    int count=0;
    while(1){
        if(toupper(*p1)==toupper(*p2)){
            if(p2!=text&&*(p2-1)!=' '){
                p2++;
                continue;
            }
            while(*p1!='\0'&&*p1!='\n'&&toupper(*p1)==toupper(*p2)){
                p1++;
                p2++;
            }
            if((*p1=='\0'||*p1=='\n')&&(*p2==' '||*p2=='\0'||*p2=='\n')){
                count++;
            }
            p1=target;
        }else if(*p2=='\n'){
            break;
        }else{
            p2++;
        }
    }
    return count;
}
int first_appearance(char target[11],char text[1000001]){
    int position=0;
    char *p1=target;
    char *p2=text;
    while(1){
        if(toupper(*p1)==toupper(*p2)){
            if(p2!=text&&*(p2-1)!=' '){
                p2++;
                position++;
                continue;
            }
            while(*p1!='\0'&&*p1!='\n'&&toupper(*p1)==toupper(*p2)){
                p1++;
                p2++;
                position++;
            }
            if((*p1=='\0'||*p1=='\n')&&(*p2==' '||*p2=='\0'||*p2=='\n')){
                return position-strlen(target);
            }
            p1=target;
        }else if(*p2=='\0'||*p2=='\n'){
            break;
        }else{
            p2++;
            position++;
        }
    }
    return -1;
}
int main(){
    char target[11];
    fgets(target,sizeof(target),stdin);
    char text[1000001];
    fgets(text,sizeof(text),stdin);
    target[strcspn(target,"\n")]='\0';
    int count=target_count(target,text);
    int first_position=first_appearance(target,text);
    if(count>0){
        printf("%d %d",count,first_position);
    }else{
        printf("-1");
    }
    return 0;
}