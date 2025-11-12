/*任务描述
本关任务：编写函数，将三个文件进行复制拼接到一个新文件中。

相关知识（略）
编程要求
编写相应的函数，将三个文件进行复制拼接。

测试说明
平台会对你编写的代码进行测试：

测试结果为三个文件内容拼接即可，文件内容之间用回车分隔。

开始你的任务吧，祝你成功！*/
#include<stdio.h>
#include<stdlib.h>
void connect(char *filename,char *filename1,char *filename2,char *filename3){
    FILE *output=fopen(filename,"w");
    FILE *input;
    char buffer[1024];
    input=fopen(filename1,"r");
    if(input){
        while(fgets(buffer,sizeof(buffer),input)){
            fputs(buffer,output);
        }
        fclose(input);
        fputs("\n",output);
    }
    input=fopen(filename2,"r");
    if(input){
        while(fgets(buffer,sizeof(buffer),input)){
            fputs(buffer,output);
        }
        fclose(input);
        fputs("\n",output);
    }
    input=fopen(filename3,"r");
    if(input){
        while(fgets(buffer,sizeof(buffer),input)){
            fputs(buffer,output);
        }
        fclose(input);
    }
    fclose(output);
}
int main(){
    connect("C62_0.txt","C62_1.txt","C62_2.txt","C62_3.txt");
    return 0;
}