#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
    char command[100];
    fgets(command,sizeof(command),stdin);
    command[strcspn(command,"\n")]='\0';
    if(strcmp(command,"type_c test.c")==0){
        FILE *file=fopen("src/step1_1/test.c","r");
        if(file){
            char line[1024];
            int line_num=1;
            while(fgets(line,sizeof(line),file)){
                printf("%d:%s",line_num,line);
            }
            fclose(file);
        }
    }
    else if(strcmp(command,"type_c /p test.c")==0){
        FILE *file=fopen("src/step1_1/test.c","r");
        if(file){
            char line[1024];
            int line_num=1;
            int count=0;
            while(fgets(line,sizeof(line),file)){
                printf("%d:%s",line_num,line);
                line_num++;
                count++;
                if(count==10){
                    count=0;
                    char input[10];
                    fgets(input,sizeof(input),stdin);
                    if(strcmp(input,"q\n")!=0)break;
                }
            } 
            fclose(file);
        }       
    }
    else{
        printf("指令错误\n");
    }
    return 0;
}