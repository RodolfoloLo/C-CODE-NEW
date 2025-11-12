#include<stdio.h>
#include<stdlib.h>
int main(){
    //写入字符串
    char str[77]="I am because you are\n";
    char str_show[77];
    FILE *file1=fopen("test.txt","w");
    if(file1==NULL){
        printf("Failed!");
        exit(-1);
    }
    fputs(str,file1);
    fclose(file1);
    FILE *file2=fopen("test.txt","r");
    if(file2==NULL){
        printf("Failed!");
        exit(-1);
    }
    while(!feof(file2)){
        if(fgets(str_show,77,file2)!=NULL){
            printf("%s",str_show);
        }
    }
    fclose(file2);
    return 0;
}