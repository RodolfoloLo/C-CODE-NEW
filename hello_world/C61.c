#include<stdio.h>
#include<stdlib.h>
int main(){
    //写入字符串
    char str[77]="I am because you are\n";
    char str_show[77];
    FILE *file1=fopen("C61_test.txt","w");
    if(file1==NULL){
        printf("Failed!");
        exit(-1);
    }
    fputs(str,file1);
    fclose(file1);
    //读取字符串
    FILE *file2=fopen("C61_test.txt","r");
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
    FILE *file3=fopen("C61_test.txt","r");
    char ch1;
    if(file3==NULL){
        printf("Failed!");
        exit(-1);
    }
    while((ch1=fgetc(file3))!=EOF){
        putchar(ch1);
    }
    fclose(file3);
    FILE *file4=fopen("C61_test.txt","w");
    char ch2;
    if(file4==NULL){
        printf("Failed!");
        exit(-1);
    }
    while((ch2=getchar())!='\n'){
        fputc(ch2,file4);
    }
    fclose(file4);
    return 0;
}