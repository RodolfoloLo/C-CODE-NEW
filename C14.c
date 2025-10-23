#include<stdio.h>
void myrever(void){
    char ch=getchar();
    if(ch!=EOF&&ch!='\n'){
        myrever();
    }
        putchar(ch);
}
int main(){
    myrever();
    return 0;
}